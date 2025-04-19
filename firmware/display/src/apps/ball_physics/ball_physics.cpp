#include "ball_physics.h"

namespace Physics {

    enum Axis {
        Axis_X,
        Axis_Y,
    };

    struct Vec {
        int x;
        int y;
    };

    struct Ball {
        unsigned char r;
        Vec pos;
        Vec vel;
        uint32_t color;
    };

    struct LinkedList {
        LinkedList* next;
        unsigned long time;
        Axis dir;
        unsigned short index;
    };

    void add_ordered (LinkedList* head, unsigned long time, Axis dir, unsigned short index);
    void pop(LinkedList* head);
    LinkedList* next_time(LinkedList* head);

    void add_ordered (LinkedList* head, unsigned long time, Axis dir, unsigned short index) {
        LinkedList* i = head;
        while (i->next != 0 && i->next->time < time) {
            i = i->next;
        }
        LinkedList* item = {new LinkedList{i->next, time, dir, index}};
        i->next = item;
    }

    void remove_index(LinkedList* head, unsigned short index) {
        unsigned char c = 0;
        LinkedList* i = head;
        while (c < 2 && i->next != 0) {
            if (i->next->index == index) {
                c++;
                pop(i);
            }
            else {
                i = i->next;
            }
        }
    }

    void collision(Ball* b) {
        if (b->pos.x <= 1+b->r) {
            b->vel.x = abs(b->vel.x);
        } 
        else if (b->pos.x >= (20-b->r)) {
            b->vel.x = -abs(b->vel.x);
        }
        if (b->pos.y <= 1+b->r) {
            b->vel.y = abs(b->vel.y);
        } 
        else if (b->pos.y >= (56-b->r)) {
            b->vel.y = -abs(b->vel.y);
        }
    }

    LinkedList* next(LinkedList* head) {
        return head->next;
    }

    void pop(LinkedList* head) {
        LinkedList* rem = head->next;
        head->next = head->next->next;
        delete rem;
    }

    unsigned long vel_to_ms(int vel) {
        if (vel != 0) {
            return ((unsigned long)(128000 / abs(vel)));
        } else {
            return (1000000);
        }
        
    }

    void run() {
        Serial.println("Starting...");
        unsigned long f_timer = 0;
        LinkedList head = {};
        LinkedList* update_buff = &head;

        int ball_count = 6;
        Ball* balls[ball_count] = {
            new Ball{4, {10,10}, {128*10,128*18}, 0x050005},
            new Ball{2, {10,10}, {128*16,128*15}, 0x000505},
            new Ball{3, {10,10}, {128*50,128*27}, 0x500505},
            new Ball{5, {10,10}, {128*26,128*38}, 0x500500},
            new Ball{1, {10,10}, {128*60,128*10}, 0x000005},
            new Ball{4, {10,10}, {128*200,128*100}, 0x000F01},
        }; 
        
        for (int i = 0; i < ball_count; i++) {
            add_ordered(update_buff, millis(), Axis_X, i);
            add_ordered(update_buff, millis(), Axis_Y, i);
        }

        LinkedList* n = next(update_buff);
        while(!stopped()) {
            if (millis() >= n->time) {
                unsigned short i = n->index; 

                switch(n->dir) {
                    case Axis_X:
                        balls[i]->pos.x += balls[i]->vel.x > 0 ? 1 : -1;
                        collision(balls[i]);
                        add_ordered(update_buff, n->time + vel_to_ms(balls[i]->vel.x), Axis_X, i);
                    break;
                    case Axis_Y:
                        balls[i]->pos.y += balls[i]->vel.y > 0 ? 1 : -1;
                        collision(balls[i]);
                        
                        add_ordered(update_buff, n->time + vel_to_ms(balls[i]->vel.y), Axis_Y, i);
                    break;
                }
                pop(update_buff);
                n = next(update_buff);
            }
            if (millis() - f_timer >= 16) {
                f_timer = millis();
                GFX::clear();
                for (int i = 0; i < ball_count; i++) {
                    GFX::drawEllipse(balls[i]->r, balls[i]->r, balls[i]->pos.y, balls[i]->pos.x, balls[i]->color);
                }
                LED::write();
            }
        }
    }


    bool stopped() {
        return(Key::is_pressed(Key::ESC));
    }

}

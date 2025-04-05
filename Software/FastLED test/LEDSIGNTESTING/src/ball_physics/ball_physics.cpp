#include "ball_physics.h"

enum Direction {
    posX,
    posY,
    negX,
    negY,
};

struct Ball {
    unsigned char r;
    unsigned short x;
    unsigned short y;
    int tx;
    int ty;
    CRGB color;
};

struct LinkedList {
    LinkedList* next;
    unsigned long time;
    Direction dir;
    unsigned short index;
};

void add_ordered (LinkedList* head, unsigned long time, Direction dir, unsigned short index);
void pop(LinkedList* head);
LinkedList* next_time(LinkedList* head);

void add_ordered (LinkedList* head, unsigned long time, Direction dir, unsigned short index) {
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
    if (b->x <= 2+b->r) {
        b->tx = abs(b->tx);
    } 
    else if (b->x >= (19-b->r)) {
        b->tx = -abs(b->tx);
    }
    if (b->y <= 2+b->r) {
        b->ty = abs(b->ty);
    } 
    else if (b->y >= (55-b->r)) {
        b->ty = -abs(b->ty);
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
    }; 
    
    add_ordered(head_ptr, 10, posX, 0);
    add_ordered(head_ptr, 20, posY, 0);
    add_ordered(head_ptr, 200, posX, 1);
    add_ordered(head_ptr, 100, posY, 1);
    add_ordered(head_ptr, 200, posX, 2);
    add_ordered(head_ptr, 100, posY, 2);
    add_ordered(head_ptr, 200, posX, 3);
    add_ordered(head_ptr, 100, posY, 3);
    add_ordered(head_ptr, 200, posX, 4);
    add_ordered(head_ptr, 100, posY, 4);
    add_ordered(head_ptr, 200, posX, 5);
    add_ordered(head_ptr, 100, posY, 5);

    LinkedList* n = next(head_ptr);
    while(checkBallStop()) {
        if (millis() >= n->time) {
            collision(balls[n->index]);
            switch(n->dir) {
                case posX:
                    balls[n->index]->x += 1;
                    add_ordered(head_ptr, n->time + abs(balls[n->index]->tx), balls[n->index]->tx > 0 ? posX : negX, n->index);
                break;
                case posY:
                    balls[n->index]->y += 1;
                    add_ordered(head_ptr, n->time + abs(balls[n->index]->ty), balls[n->index]->ty > 0 ? posY : negY, n->index);
                break;
                case negX:
                    balls[n->index]->x -= 1;
                    add_ordered(head_ptr, n->time + abs(balls[n->index]->tx), balls[n->index]->tx > 0 ? posX : negX, n->index);
                break;
                case negY:
                    balls[n->index]->y -= 1;
                    add_ordered(head_ptr, n->time + abs(balls[n->index]->ty), balls[n->index]->ty > 0 ? posY : negY, n->index);
                break;
            }
            pop(head_ptr);
            n = next(head_ptr);
        }
        if (millis() - f_timer >= 16) {
            f_timer = millis();
            clear();
            for (int i = 0; i < 6; i++) {
                drawEllipse(balls[i]->r, balls[i]->r, balls[i]->y, balls[i]->x, balls[i]->color);
            }
            FastLED.show();
        }
    }
}


bool checkBallStop() {
    return (true);
}

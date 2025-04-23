#ifndef BITMAPS
#define BITMAPS

#include "../types.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

namespace GFX {

	struct Bitmap {
		u16_t wid;
		u16_t hth;
		u16_t size;
		u32_t* palette;
		u8_t* bitmap;
	};

}

namespace Bitmaps {

	static u32_t palette_rainbow[6] = {0xFF0000FF, 0xFFA500FF, 0xFFFF00FF, 0x00FF00FF, 0x0000FFFF, 0x00FFFFFF};
	static u8_t data_rainbow[12] = {0x00, 0x80, 0x24, 0x89, 0x24, 0x69, 0xdb, 0x46, 0x92, 0x6c, 0xdb, 0x02};
	static GFX::Bitmap* rainbow = new GFX::Bitmap{5, 6, 6, palette_rainbow, data_rainbow};

	static u8_t data_space[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
	static GFX::Bitmap* space = new GFX::Bitmap{5, 7, 1, NULL, data_space};

	static u8_t data_A[5] = {0x2e, 0xfe, 0x18, 0x63, 0x04};
	static GFX::Bitmap* A = new GFX::Bitmap{5, 7, 2, NULL, data_A};

	static u8_t data_a[5] = {0x00, 0x38, 0xe8, 0xa3, 0x07};
	static GFX::Bitmap* a = new GFX::Bitmap{5, 7, 2, NULL, data_a};

	static u8_t data_B[5] = {0x2f, 0xbe, 0x18, 0xe3, 0x03};
	static GFX::Bitmap* B = new GFX::Bitmap{5, 7, 2, NULL, data_B};

	static u8_t data_b[5] = {0x21, 0xb4, 0x19, 0xe3, 0x03};
	static GFX::Bitmap* b = new GFX::Bitmap{5, 7, 2, NULL, data_b};

	static u8_t data_C[5] = {0x3e, 0x84, 0x10, 0x82, 0x07};
	static GFX::Bitmap* C = new GFX::Bitmap{5, 7, 2, NULL, data_C};

	static u8_t data_c[5] = {0x00, 0xb8, 0x18, 0xa2, 0x03};
	static GFX::Bitmap* c = new GFX::Bitmap{5, 7, 2, NULL, data_c};

	static u8_t data_D[5] = {0x2f, 0xc6, 0x18, 0xe3, 0x03};
	static GFX::Bitmap* D = new GFX::Bitmap{5, 7, 2, NULL, data_D};

	static u8_t data_d[5] = {0x08, 0xb9, 0x94, 0x92, 0x05};
	static GFX::Bitmap* d = new GFX::Bitmap{5, 7, 2, NULL, data_d};

	static u8_t data_E[5] = {0x3f, 0x84, 0x1f, 0xc2, 0x07};
	static GFX::Bitmap* E = new GFX::Bitmap{5, 7, 2, NULL, data_E};

	static u8_t data_e[5] = {0x00, 0xb8, 0xf8, 0x82, 0x07};
	static GFX::Bitmap* e = new GFX::Bitmap{5, 7, 2, NULL, data_e};

	static u8_t data_F[5] = {0x3f, 0x84, 0x17, 0x42, 0x00};
	static GFX::Bitmap* F = new GFX::Bitmap{5, 7, 2, NULL, data_F};

	static u8_t data_f[5] = {0x4c, 0x8a, 0x27, 0x84, 0x00};
	static GFX::Bitmap* f = new GFX::Bitmap{5, 7, 2, NULL, data_f};

	static u8_t data_G[5] = {0x2e, 0x84, 0x1e, 0xa3, 0x03};
	static GFX::Bitmap* G = new GFX::Bitmap{5, 7, 2, NULL, data_G};

	static u8_t data_g[5] = {0xc0, 0xc7, 0xe8, 0xe1, 0x03};
	static GFX::Bitmap* g = new GFX::Bitmap{5, 7, 2, NULL, data_g};

	static u8_t data_H[5] = {0x31, 0xc6, 0x1f, 0x63, 0x04};
	static GFX::Bitmap* H = new GFX::Bitmap{5, 7, 2, NULL, data_H};

	static u8_t data_h[5] = {0x21, 0xb4, 0x19, 0x63, 0x04};
	static GFX::Bitmap* h = new GFX::Bitmap{5, 7, 2, NULL, data_h};

	static u8_t data_I[5] = {0x9f, 0x10, 0x42, 0xc8, 0x07};
	static GFX::Bitmap* I = new GFX::Bitmap{5, 7, 2, NULL, data_I};

	static u8_t data_i[5] = {0x04, 0x18, 0x42, 0x88, 0x03};
	static GFX::Bitmap* i = new GFX::Bitmap{5, 7, 2, NULL, data_i};

	static u8_t data_J[5] = {0x1c, 0x21, 0x84, 0x92, 0x01};
	static GFX::Bitmap* J = new GFX::Bitmap{5, 7, 2, NULL, data_J};

	static u8_t data_j[5] = {0x08, 0x30, 0x84, 0x92, 0x01};
	static GFX::Bitmap* j = new GFX::Bitmap{5, 7, 2, NULL, data_j};

	static u8_t data_K[5] = {0x31, 0x95, 0x51, 0x52, 0x04};
	static GFX::Bitmap* K = new GFX::Bitmap{5, 7, 2, NULL, data_K};

	static u8_t data_k[5] = {0x20, 0xa4, 0x32, 0x4a, 0x06};
	static GFX::Bitmap* k = new GFX::Bitmap{5, 7, 2, NULL, data_k};

	static u8_t data_L[5] = {0x21, 0x84, 0x10, 0xc2, 0x07};
	static GFX::Bitmap* L = new GFX::Bitmap{5, 7, 2, NULL, data_L};

	static u8_t data_l[5] = {0x86, 0x10, 0x42, 0x08, 0x06};
	static GFX::Bitmap* l = new GFX::Bitmap{5, 7, 2, NULL, data_l};

	static u8_t data_M[5] = {0x71, 0xd7, 0x18, 0x63, 0x04};
	static GFX::Bitmap* M = new GFX::Bitmap{5, 7, 2, NULL, data_M};

	static u8_t data_m[5] = {0x00, 0xac, 0x5a, 0x6b, 0x05};
	static GFX::Bitmap* m = new GFX::Bitmap{5, 7, 2, NULL, data_m};

	static u8_t data_N[5] = {0x71, 0xd6, 0x5a, 0x73, 0x04};
	static GFX::Bitmap* N = new GFX::Bitmap{5, 7, 2, NULL, data_N};

	static u8_t data_n[5] = {0x00, 0xb4, 0x19, 0x63, 0x04};
	static GFX::Bitmap* n = new GFX::Bitmap{5, 7, 2, NULL, data_n};

	static u8_t data_O[5] = {0x2e, 0xc6, 0x18, 0xa3, 0x03};
	static GFX::Bitmap* O = new GFX::Bitmap{5, 7, 2, NULL, data_O};

	static u8_t data_o[5] = {0x00, 0xb8, 0x18, 0xa3, 0x03};
	static GFX::Bitmap* o = new GFX::Bitmap{5, 7, 2, NULL, data_o};

	static u8_t data_P[5] = {0x2f, 0xc6, 0x17, 0x42, 0x00};
	static GFX::Bitmap* P = new GFX::Bitmap{5, 7, 2, NULL, data_P};

	static u8_t data_p[5] = {0xa0, 0xcd, 0xf8, 0x42, 0x00};
	static GFX::Bitmap* p = new GFX::Bitmap{5, 7, 2, NULL, data_p};

	static u8_t data_Q[5] = {0x2e, 0xc6, 0x58, 0x93, 0x05};
	static GFX::Bitmap* Q = new GFX::Bitmap{5, 7, 2, NULL, data_Q};

	static u8_t data_q[5] = {0xc0, 0xa5, 0xe4, 0x10, 0x06};
	static GFX::Bitmap* q = new GFX::Bitmap{5, 7, 2, NULL, data_q};

	static u8_t data_R[5] = {0x2f, 0xc6, 0x57, 0x52, 0x04};
	static GFX::Bitmap* R = new GFX::Bitmap{5, 7, 2, NULL, data_R};

	static u8_t data_r[5] = {0x00, 0xb4, 0x19, 0x42, 0x00};
	static GFX::Bitmap* r = new GFX::Bitmap{5, 7, 2, NULL, data_r};

	static u8_t data_S[5] = {0x2e, 0x06, 0x07, 0xa3, 0x03};
	static GFX::Bitmap* S = new GFX::Bitmap{5, 7, 2, NULL, data_S};

	static u8_t data_s[5] = {0x00, 0xf8, 0xe0, 0xe0, 0x03};
	static GFX::Bitmap* s = new GFX::Bitmap{5, 7, 2, NULL, data_s};

	static u8_t data_T[5] = {0x9f, 0x10, 0x42, 0x08, 0x01};
	static GFX::Bitmap* T = new GFX::Bitmap{5, 7, 2, NULL, data_T};

	static u8_t data_t[5] = {0x42, 0x3c, 0x21, 0x04, 0x03};
	static GFX::Bitmap* t = new GFX::Bitmap{5, 7, 2, NULL, data_t};

	static u8_t data_U[5] = {0x31, 0xc6, 0x18, 0xa3, 0x03};
	static GFX::Bitmap* U = new GFX::Bitmap{5, 7, 2, NULL, data_U};

	static u8_t data_u[5] = {0x00, 0xa4, 0x94, 0x92, 0x05};
	static GFX::Bitmap* u = new GFX::Bitmap{5, 7, 2, NULL, data_u};

	static u8_t data_V[5] = {0x31, 0xc6, 0xa8, 0x14, 0x01};
	static GFX::Bitmap* V = new GFX::Bitmap{5, 7, 2, NULL, data_V};

	static u8_t data_v[5] = {0x00, 0xc4, 0x18, 0x15, 0x01};
	static GFX::Bitmap* v = new GFX::Bitmap{5, 7, 2, NULL, data_v};

	static u8_t data_W[5] = {0x31, 0xc6, 0x58, 0x77, 0x04};
	static GFX::Bitmap* W = new GFX::Bitmap{5, 7, 2, NULL, data_W};

	static u8_t data_w[5] = {0x00, 0xc4, 0x58, 0x95, 0x02};
	static GFX::Bitmap* w = new GFX::Bitmap{5, 7, 2, NULL, data_w};

	static u8_t data_X[5] = {0x31, 0x2a, 0xa2, 0x62, 0x04};
	static GFX::Bitmap* X = new GFX::Bitmap{5, 7, 2, NULL, data_X};

	static u8_t data_x[5] = {0x00, 0x44, 0x45, 0x54, 0x04};
	static GFX::Bitmap* x = new GFX::Bitmap{5, 7, 2, NULL, data_x};

	static u8_t data_Y[5] = {0x31, 0x2a, 0x42, 0x08, 0x01};
	static GFX::Bitmap* Y = new GFX::Bitmap{5, 7, 2, NULL, data_Y};

	static u8_t data_y[5] = {0x00, 0xc4, 0xe8, 0xe1, 0x03};
	static GFX::Bitmap* y = new GFX::Bitmap{5, 7, 2, NULL, data_y};

	static u8_t data_Z[5] = {0x1f, 0x22, 0x22, 0xc2, 0x07};
	static GFX::Bitmap* Z = new GFX::Bitmap{5, 7, 2, NULL, data_Z};

	static u8_t data_z[5] = {0x00, 0x7c, 0x44, 0xc4, 0x07};
	static GFX::Bitmap* z = new GFX::Bitmap{5, 7, 2, NULL, data_z};

	static u8_t data_n0[5] = {0x2e, 0xce, 0x9a, 0xa3, 0x03};
	static GFX::Bitmap* n0 = new GFX::Bitmap{5, 7, 2, NULL, data_n0};

	static u8_t data_n1[5] = {0xc4, 0x14, 0x42, 0xc8, 0x07};
	static GFX::Bitmap* n1 = new GFX::Bitmap{5, 7, 2, NULL, data_n1};

	static u8_t data_n2[5] = {0x2e, 0x42, 0x44, 0xc4, 0x07};
	static GFX::Bitmap* n2 = new GFX::Bitmap{5, 7, 2, NULL, data_n2};

	static u8_t data_n3[5] = {0x2e, 0x42, 0x06, 0xa3, 0x03};
	static GFX::Bitmap* n3 = new GFX::Bitmap{5, 7, 2, NULL, data_n3};

	static u8_t data_n4[5] = {0x4c, 0xa5, 0x8f, 0x10, 0x02};
	static GFX::Bitmap* n4 = new GFX::Bitmap{5, 7, 2, NULL, data_n4};

	static u8_t data_n5[5] = {0x3f, 0x3c, 0x08, 0xa3, 0x03};
	static GFX::Bitmap* n5 = new GFX::Bitmap{5, 7, 2, NULL, data_n5};

	static u8_t data_n6[5] = {0x5c, 0x04, 0x17, 0xa3, 0x03};
	static GFX::Bitmap* n6 = new GFX::Bitmap{5, 7, 2, NULL, data_n6};

	static u8_t data_n7[5] = {0x1f, 0x42, 0x84, 0x08, 0x01};
	static GFX::Bitmap* n7 = new GFX::Bitmap{5, 7, 2, NULL, data_n7};

	static u8_t data_n8[5] = {0x2e, 0x46, 0x17, 0xa3, 0x03};
	static GFX::Bitmap* n8 = new GFX::Bitmap{5, 7, 2, NULL, data_n8};

	static u8_t data_n9[5] = {0x2e, 0x46, 0x0f, 0x91, 0x01};
	static GFX::Bitmap* n9 = new GFX::Bitmap{5, 7, 2, NULL, data_n9};

	static u8_t data_exclimation[5] = {0x84, 0x10, 0x42, 0x00, 0x01};
	static GFX::Bitmap* exclimation = new GFX::Bitmap{5, 7, 2, NULL, data_exclimation};

	static u8_t data_dquote[5] = {0x4a, 0x01, 0x00, 0x00, 0x00};
	static GFX::Bitmap* dquote = new GFX::Bitmap{5, 7, 2, NULL, data_dquote};

	static u8_t data_hashtag[5] = {0x40, 0x7d, 0xf5, 0x15, 0x00};
	static GFX::Bitmap* hashtag = new GFX::Bitmap{5, 7, 2, NULL, data_hashtag};

	static u8_t data_dollar[5] = {0xae, 0x16, 0x47, 0xab, 0x03};
	static GFX::Bitmap* dollar = new GFX::Bitmap{5, 7, 2, NULL, data_dollar};

	static u8_t data_precent[5] = {0x73, 0x21, 0x22, 0x74, 0x06};
	static GFX::Bitmap* precent = new GFX::Bitmap{5, 7, 2, NULL, data_precent};

	static u8_t data_and_sym[5] = {0xa2, 0x88, 0x9a, 0x92, 0x05};
	static GFX::Bitmap* and_sym = new GFX::Bitmap{5, 7, 2, NULL, data_and_sym};

	static u8_t data_squote[5] = {0x08, 0x01, 0x00, 0x00, 0x00};
	static GFX::Bitmap* squote = new GFX::Bitmap{5, 7, 2, NULL, data_squote};

	static u8_t data_lpar[5] = {0x88, 0x08, 0x21, 0x08, 0x02};
	static GFX::Bitmap* lpar = new GFX::Bitmap{5, 7, 2, NULL, data_lpar};

	static u8_t data_rpar[5] = {0x82, 0x20, 0x84, 0x88, 0x00};
	static GFX::Bitmap* rpar = new GFX::Bitmap{5, 7, 2, NULL, data_rpar};

	static u8_t data_star[5] = {0x8a, 0x28, 0x00, 0x00, 0x00};
	static GFX::Bitmap* star = new GFX::Bitmap{5, 7, 2, NULL, data_star};

	static u8_t data_plus[5] = {0x80, 0x90, 0x4f, 0x08, 0x00};
	static GFX::Bitmap* plus = new GFX::Bitmap{5, 7, 2, NULL, data_plus};

	static u8_t data_comma[5] = {0x00, 0x00, 0x00, 0x44, 0x00};
	static GFX::Bitmap* comma = new GFX::Bitmap{5, 7, 2, NULL, data_comma};

	static u8_t data_minus[5] = {0x00, 0x80, 0x0f, 0x00, 0x00};
	static GFX::Bitmap* minus = new GFX::Bitmap{5, 7, 2, NULL, data_minus};

	static u8_t data_period[5] = {0x00, 0x00, 0x00, 0x40, 0x00};
	static GFX::Bitmap* period = new GFX::Bitmap{5, 7, 2, NULL, data_period};

	static u8_t data_fslash[5] = {0x10, 0x21, 0x22, 0x44, 0x00};
	static GFX::Bitmap* fslash = new GFX::Bitmap{5, 7, 2, NULL, data_fslash};

	static u8_t data_colon[5] = {0x00, 0x10, 0x00, 0x08, 0x00};
	static GFX::Bitmap* colon = new GFX::Bitmap{5, 7, 2, NULL, data_colon};

	static u8_t data_semicolon[5] = {0x00, 0x10, 0x00, 0x88, 0x00};
	static GFX::Bitmap* semicolon = new GFX::Bitmap{5, 7, 2, NULL, data_semicolon};

	static u8_t data_less[5] = {0x10, 0x11, 0x41, 0x10, 0x04};
	static GFX::Bitmap* less = new GFX::Bitmap{5, 7, 2, NULL, data_less};

	static u8_t data_equal[5] = {0x00, 0x7c, 0xf0, 0x01, 0x00};
	static GFX::Bitmap* equal = new GFX::Bitmap{5, 7, 2, NULL, data_equal};

	static u8_t data_greater[5] = {0x41, 0x10, 0x44, 0x44, 0x00};
	static GFX::Bitmap* greater = new GFX::Bitmap{5, 7, 2, NULL, data_greater};

	static u8_t data_question[5] = {0x2e, 0x22, 0x42, 0x00, 0x01};
	static GFX::Bitmap* question = new GFX::Bitmap{5, 7, 2, NULL, data_question};

	static u8_t data_at[5] = {0x2e, 0xd6, 0xda, 0x83, 0x03};
	static GFX::Bitmap* at = new GFX::Bitmap{5, 7, 2, NULL, data_at};

	static u8_t data_lsquare[5] = {0x9c, 0x10, 0x42, 0x08, 0x07};
	static GFX::Bitmap* lsquare = new GFX::Bitmap{5, 7, 2, NULL, data_lsquare};

	static u8_t data_bslash[5] = {0x41, 0x08, 0x82, 0x10, 0x04};
	static GFX::Bitmap* bslash = new GFX::Bitmap{5, 7, 2, NULL, data_bslash};

	static u8_t data_rsquare[5] = {0x87, 0x10, 0x42, 0xc8, 0x01};
	static GFX::Bitmap* rsquare = new GFX::Bitmap{5, 7, 2, NULL, data_rsquare};

	static u8_t data_carrot[5] = {0x44, 0x45, 0x00, 0x00, 0x00};
	static GFX::Bitmap* carrot = new GFX::Bitmap{5, 7, 2, NULL, data_carrot};

	static u8_t data_under[5] = {0x00, 0x00, 0x00, 0xc0, 0x07};
	static GFX::Bitmap* under = new GFX::Bitmap{5, 7, 2, NULL, data_under};

	static u8_t data_accent[5] = {0x41, 0x00, 0x00, 0x00, 0x00};
	static GFX::Bitmap* accent = new GFX::Bitmap{5, 7, 2, NULL, data_accent};

	static u8_t data_lcurly[5] = {0x98, 0x20, 0x82, 0x08, 0x06};
	static GFX::Bitmap* lcurly = new GFX::Bitmap{5, 7, 2, NULL, data_lcurly};

	static u8_t data_pipe[5] = {0x84, 0x10, 0x42, 0x08, 0x01};
	static GFX::Bitmap* pipe = new GFX::Bitmap{5, 7, 2, NULL, data_pipe};

	static u8_t data_rcurly[5] = {0x83, 0x08, 0x22, 0xc8, 0x00};
	static GFX::Bitmap* rcurly = new GFX::Bitmap{5, 7, 2, NULL, data_rcurly};

	static u8_t data_tilde[5] = {0x45, 0x01, 0x00, 0x00, 0x00};
	static GFX::Bitmap* tilde = new GFX::Bitmap{5, 7, 2, NULL, data_tilde};

	static u8_t data_Dino[4] = {0x3f, 0xee, 0xf8, 0x01};
	static GFX::Bitmap* Dino = new GFX::Bitmap{5, 5, 2, NULL, data_Dino};

	static u8_t data_Cactus[4] = {0x84, 0xd6, 0x4f, 0x08};
	static GFX::Bitmap* Cactus = new GFX::Bitmap{5, 6, 2, NULL, data_Cactus};

	static u8_t data_UFO[3] = {0x1c, 0xd1, 0x1f};
	static GFX::Bitmap* UFO = new GFX::Bitmap{7, 3, 2, NULL, data_UFO};

	static u32_t palette_Snake_Menu[3] = {0x000000, 0x00FF00, 0xFF0000};
	static u8_t data_Snake_Menu[24] = {0x00, 0x00, 0x00, 0x50, 0x15, 0x00, 0x10, 0x10, 0x10, 0x14, 0x50, 0x15, 0x04, 0x00, 0x00, 0x14, 0x55, 0x01, 0x10, 0x01, 0x95, 0x50, 0x01, 0x00};
	static GFX::Bitmap* Snake_Menu = new GFX::Bitmap{12, 8, 3, palette_Snake_Menu, data_Snake_Menu};

}

namespace Font {

	static GFX::Bitmap* font_5x7[128] = {Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::space, Bitmaps::exclimation, Bitmaps::dquote, Bitmaps::hashtag, Bitmaps::dollar, Bitmaps::precent, Bitmaps::and_sym, Bitmaps::squote, Bitmaps::lpar, Bitmaps::rpar, Bitmaps::star, Bitmaps::plus, Bitmaps::comma, Bitmaps::minus, Bitmaps::period, Bitmaps::fslash, Bitmaps::n0, Bitmaps::n1, Bitmaps::n2, Bitmaps::n3, Bitmaps::n4, Bitmaps::n5, Bitmaps::n6, Bitmaps::n7, Bitmaps::n8, Bitmaps::n9, Bitmaps::colon, Bitmaps::semicolon, Bitmaps::less, Bitmaps::equal, Bitmaps::greater, Bitmaps::question, Bitmaps::at, Bitmaps::A, Bitmaps::B, Bitmaps::C, Bitmaps::D, Bitmaps::E, Bitmaps::F, Bitmaps::G, Bitmaps::H, Bitmaps::I, Bitmaps::J, Bitmaps::K, Bitmaps::L, Bitmaps::M, Bitmaps::N, Bitmaps::O, Bitmaps::P, Bitmaps::Q, Bitmaps::R, Bitmaps::S, Bitmaps::T, Bitmaps::U, Bitmaps::V, Bitmaps::W, Bitmaps::X, Bitmaps::Y, Bitmaps::Z, Bitmaps::lsquare, Bitmaps::bslash, Bitmaps::rsquare, Bitmaps::carrot, Bitmaps::under, Bitmaps::accent, Bitmaps::a, Bitmaps::b, Bitmaps::c, Bitmaps::d, Bitmaps::e, Bitmaps::f, Bitmaps::g, Bitmaps::h, Bitmaps::i, Bitmaps::j, Bitmaps::k, Bitmaps::l, Bitmaps::m, Bitmaps::n, Bitmaps::o, Bitmaps::p, Bitmaps::q, Bitmaps::r, Bitmaps::s, Bitmaps::t, Bitmaps::u, Bitmaps::v, Bitmaps::w, Bitmaps::x, Bitmaps::y, Bitmaps::z, Bitmaps::lcurly, Bitmaps::pipe, Bitmaps::rcurly, Bitmaps::tilde, Bitmaps::space};

}

#pragma GCC diagnostic pop

#endif
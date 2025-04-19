#ifndef BITMAPS
#define BITMAPS
#include <Arduino.h>
#include "../driver/driver.h"
#include "../graphics/graphics.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

namespace Bitmaps {

	static uint32_t palette_rainbow[6] = {0xFF0000FF, 0xFFA500FF, 0xFFFF00FF, 0x00FF00FF, 0x0000FFFF, 0x00FFFFFF};
	static uint8_t data_rainbow[12] = {0x00, 0x80, 0x24, 0x89, 0x24, 0x69, 0xdb, 0x46, 0x92, 0x6c, 0xdb, 0x02};
	static GFX::Bitmap rainbow = {5, 6, 6, palette_rainbow, data_rainbow};

	static uint8_t data_space[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
	static GFX::Bitmap space = {5, 7, 1, NULL, data_space};

	static uint8_t data_A[5] = {0x2e, 0xfe, 0x18, 0x63, 0x04};
	static GFX::Bitmap A = {5, 7, 2, NULL, data_A};

	static uint8_t data_a[5] = {0x00, 0x38, 0xe8, 0xa3, 0x07};
	static GFX::Bitmap a = {5, 7, 2, NULL, data_a};

	static uint8_t data_B[5] = {0x2f, 0xbe, 0x18, 0xe3, 0x03};
	static GFX::Bitmap B = {5, 7, 2, NULL, data_B};

	static uint8_t data_b[5] = {0x21, 0xb4, 0x19, 0xe3, 0x03};
	static GFX::Bitmap b = {5, 7, 2, NULL, data_b};

	static uint8_t data_C[5] = {0x3e, 0x84, 0x10, 0x82, 0x07};
	static GFX::Bitmap C = {5, 7, 2, NULL, data_C};

	static uint8_t data_c[5] = {0x00, 0xb8, 0x18, 0xa2, 0x03};
	static GFX::Bitmap c = {5, 7, 2, NULL, data_c};

	static uint8_t data_D[5] = {0x2f, 0xc6, 0x18, 0xe3, 0x03};
	static GFX::Bitmap D = {5, 7, 2, NULL, data_D};

	static uint8_t data_d[5] = {0x08, 0xb9, 0x94, 0x92, 0x05};
	static GFX::Bitmap d = {5, 7, 2, NULL, data_d};

	static uint8_t data_E[5] = {0x3f, 0x84, 0x1f, 0xc2, 0x07};
	static GFX::Bitmap E = {5, 7, 2, NULL, data_E};

	static uint8_t data_e[5] = {0x00, 0xb8, 0xf8, 0x82, 0x07};
	static GFX::Bitmap e = {5, 7, 2, NULL, data_e};

	static uint8_t data_F[5] = {0x3f, 0x84, 0x17, 0x42, 0x00};
	static GFX::Bitmap F = {5, 7, 2, NULL, data_F};

	static uint8_t data_f[5] = {0x4c, 0x8a, 0x27, 0x84, 0x00};
	static GFX::Bitmap f = {5, 7, 2, NULL, data_f};

	static uint8_t data_G[5] = {0x2e, 0x84, 0x1e, 0xa3, 0x03};
	static GFX::Bitmap G = {5, 7, 2, NULL, data_G};

	static uint8_t data_g[5] = {0xc0, 0xc7, 0xe8, 0xe1, 0x03};
	static GFX::Bitmap g = {5, 7, 2, NULL, data_g};

	static uint8_t data_H[5] = {0x31, 0xc6, 0x1f, 0x63, 0x04};
	static GFX::Bitmap H = {5, 7, 2, NULL, data_H};

	static uint8_t data_h[5] = {0x21, 0xb4, 0x19, 0x63, 0x04};
	static GFX::Bitmap h = {5, 7, 2, NULL, data_h};

	static uint8_t data_I[5] = {0x9f, 0x10, 0x42, 0xc8, 0x07};
	static GFX::Bitmap I = {5, 7, 2, NULL, data_I};

	static uint8_t data_i[5] = {0x04, 0x18, 0x42, 0x88, 0x03};
	static GFX::Bitmap i = {5, 7, 2, NULL, data_i};

	static uint8_t data_J[9] = {0x60, 0x01, 0x01, 0x04, 0x10, 0x40, 0x04, 0x41, 0x01};
	static GFX::Bitmap J = {5, 7, 3, NULL, data_J};

	static uint8_t data_j[5] = {0x08, 0x30, 0x84, 0x92, 0x01};
	static GFX::Bitmap j = {5, 7, 2, NULL, data_j};

	static uint8_t data_K[5] = {0x31, 0x95, 0x51, 0x52, 0x04};
	static GFX::Bitmap K = {5, 7, 2, NULL, data_K};

	static uint8_t data_k[5] = {0x20, 0xa4, 0x32, 0x4a, 0x06};
	static GFX::Bitmap k = {5, 7, 2, NULL, data_k};

	static uint8_t data_L[5] = {0x21, 0x84, 0x10, 0xc2, 0x07};
	static GFX::Bitmap L = {5, 7, 2, NULL, data_L};

	static uint8_t data_l[5] = {0x86, 0x10, 0x42, 0x08, 0x06};
	static GFX::Bitmap l = {5, 7, 2, NULL, data_l};

	static uint8_t data_M[5] = {0x71, 0xd7, 0x18, 0x63, 0x04};
	static GFX::Bitmap M = {5, 7, 2, NULL, data_M};

	static uint8_t data_m[5] = {0x00, 0xac, 0x5a, 0x6b, 0x05};
	static GFX::Bitmap m = {5, 7, 2, NULL, data_m};

	static uint8_t data_N[5] = {0x71, 0xd6, 0x5a, 0x73, 0x04};
	static GFX::Bitmap N = {5, 7, 2, NULL, data_N};

	static uint8_t data_n[5] = {0x00, 0xb4, 0x19, 0x63, 0x04};
	static GFX::Bitmap n = {5, 7, 2, NULL, data_n};

	static uint8_t data_O[5] = {0x2e, 0xc6, 0x18, 0xa3, 0x03};
	static GFX::Bitmap O = {5, 7, 2, NULL, data_O};

	static uint8_t data_o[5] = {0x00, 0xb8, 0x18, 0xa3, 0x03};
	static GFX::Bitmap o = {5, 7, 2, NULL, data_o};

	static uint8_t data_P[5] = {0x2f, 0xc6, 0x17, 0x42, 0x00};
	static GFX::Bitmap P = {5, 7, 2, NULL, data_P};

	static uint8_t data_p[5] = {0xa0, 0xcd, 0xf8, 0x42, 0x00};
	static GFX::Bitmap p = {5, 7, 2, NULL, data_p};

	static uint8_t data_Q[5] = {0x2e, 0xc6, 0x58, 0x93, 0x05};
	static GFX::Bitmap Q = {5, 7, 2, NULL, data_Q};

	static uint8_t data_q[5] = {0xc0, 0xa5, 0xe4, 0x10, 0x06};
	static GFX::Bitmap q = {5, 7, 2, NULL, data_q};

	static uint8_t data_R[5] = {0x2f, 0xc6, 0x57, 0x52, 0x04};
	static GFX::Bitmap R = {5, 7, 2, NULL, data_R};

	static uint8_t data_r[5] = {0x00, 0xb4, 0x19, 0x42, 0x00};
	static GFX::Bitmap r = {5, 7, 2, NULL, data_r};

	static uint8_t data_S[5] = {0x2e, 0x06, 0x07, 0xa3, 0x03};
	static GFX::Bitmap S = {5, 7, 2, NULL, data_S};

	static uint8_t data_s[5] = {0x00, 0xf8, 0xe0, 0xe0, 0x03};
	static GFX::Bitmap s = {5, 7, 2, NULL, data_s};

	static uint8_t data_T[5] = {0x9f, 0x10, 0x42, 0x08, 0x01};
	static GFX::Bitmap T = {5, 7, 2, NULL, data_T};

	static uint8_t data_t[5] = {0x42, 0x3c, 0x21, 0x04, 0x03};
	static GFX::Bitmap t = {5, 7, 2, NULL, data_t};

	static uint8_t data_U[5] = {0x31, 0xc6, 0x18, 0xa3, 0x03};
	static GFX::Bitmap U = {5, 7, 2, NULL, data_U};

	static uint8_t data_u[5] = {0x00, 0xa4, 0x94, 0x92, 0x05};
	static GFX::Bitmap u = {5, 7, 2, NULL, data_u};

	static uint8_t data_V[5] = {0x31, 0xc6, 0xa8, 0x14, 0x01};
	static GFX::Bitmap V = {5, 7, 2, NULL, data_V};

	static uint8_t data_v[5] = {0x00, 0xc4, 0x18, 0x15, 0x01};
	static GFX::Bitmap v = {5, 7, 2, NULL, data_v};

	static uint8_t data_W[5] = {0x31, 0xc6, 0x58, 0x77, 0x04};
	static GFX::Bitmap W = {5, 7, 2, NULL, data_W};

	static uint8_t data_w[5] = {0x00, 0xc4, 0x58, 0x95, 0x02};
	static GFX::Bitmap w = {5, 7, 2, NULL, data_w};

	static uint8_t data_X[5] = {0x31, 0x2a, 0xa2, 0x62, 0x04};
	static GFX::Bitmap X = {5, 7, 2, NULL, data_X};

	static uint8_t data_x[5] = {0x00, 0x44, 0x45, 0x54, 0x04};
	static GFX::Bitmap x = {5, 7, 2, NULL, data_x};

	static uint8_t data_Y[5] = {0x31, 0x2a, 0x42, 0x08, 0x01};
	static GFX::Bitmap Y = {5, 7, 2, NULL, data_Y};

	static uint8_t data_y[5] = {0x00, 0xc4, 0xe8, 0xe1, 0x03};
	static GFX::Bitmap y = {5, 7, 2, NULL, data_y};

	static uint8_t data_Z[5] = {0x1f, 0x22, 0x22, 0xc2, 0x07};
	static GFX::Bitmap Z = {5, 7, 2, NULL, data_Z};

	static uint8_t data_z[5] = {0x00, 0x7c, 0x44, 0xc4, 0x07};
	static GFX::Bitmap z = {5, 7, 2, NULL, data_z};

	static uint8_t data_n0[5] = {0x2e, 0xce, 0x9a, 0xa3, 0x03};
	static GFX::Bitmap n0 = {5, 7, 2, NULL, data_n0};

	static uint8_t data_n1[5] = {0xc4, 0x14, 0x42, 0xc8, 0x07};
	static GFX::Bitmap n1 = {5, 7, 2, NULL, data_n1};

	static uint8_t data_n2[5] = {0x2e, 0x42, 0x44, 0xc4, 0x07};
	static GFX::Bitmap n2 = {5, 7, 2, NULL, data_n2};

	static uint8_t data_n3[5] = {0x2e, 0x42, 0x06, 0xa3, 0x03};
	static GFX::Bitmap n3 = {5, 7, 2, NULL, data_n3};

	static uint8_t data_n4[5] = {0x4c, 0xa5, 0x8f, 0x10, 0x02};
	static GFX::Bitmap n4 = {5, 7, 2, NULL, data_n4};

	static uint8_t data_n5[5] = {0x3f, 0x3c, 0x08, 0xa3, 0x03};
	static GFX::Bitmap n5 = {5, 7, 2, NULL, data_n5};

	static uint8_t data_n6[5] = {0x5c, 0x04, 0x17, 0xa3, 0x03};
	static GFX::Bitmap n6 = {5, 7, 2, NULL, data_n6};

	static uint8_t data_n7[5] = {0x1f, 0x42, 0x84, 0x08, 0x01};
	static GFX::Bitmap n7 = {5, 7, 2, NULL, data_n7};

	static uint8_t data_n8[5] = {0x2e, 0x46, 0x17, 0xa3, 0x03};
	static GFX::Bitmap n8 = {5, 7, 2, NULL, data_n8};

	static uint8_t data_n9[5] = {0x2e, 0x46, 0x0f, 0x91, 0x01};
	static GFX::Bitmap n9 = {5, 7, 2, NULL, data_n9};

	static uint8_t data_exclimation[5] = {0x84, 0x10, 0x42, 0x00, 0x01};
	static GFX::Bitmap exclimation = {5, 7, 2, NULL, data_exclimation};

	static uint8_t data_dquote[5] = {0x4a, 0x01, 0x00, 0x00, 0x00};
	static GFX::Bitmap dquote = {5, 7, 2, NULL, data_dquote};

	static uint8_t data_hashtag[5] = {0x40, 0x7d, 0xf5, 0x15, 0x00};
	static GFX::Bitmap hashtag = {5, 7, 2, NULL, data_hashtag};

	static uint8_t data_dollar[5] = {0xae, 0x16, 0x47, 0xab, 0x03};
	static GFX::Bitmap dollar = {5, 7, 2, NULL, data_dollar};

	static uint8_t data_precent[5] = {0x73, 0x21, 0x22, 0x74, 0x06};
	static GFX::Bitmap precent = {5, 7, 2, NULL, data_precent};

	static uint8_t data_and_sym[5] = {0xa2, 0x88, 0x9a, 0x92, 0x05};
	static GFX::Bitmap and_sym = {5, 7, 2, NULL, data_and_sym};

	static uint8_t data_squote[5] = {0x08, 0x01, 0x00, 0x00, 0x00};
	static GFX::Bitmap squote = {5, 7, 2, NULL, data_squote};

	static uint8_t data_lpar[5] = {0x88, 0x08, 0x21, 0x08, 0x02};
	static GFX::Bitmap lpar = {5, 7, 2, NULL, data_lpar};

	static uint8_t data_rpar[5] = {0x82, 0x20, 0x84, 0x88, 0x00};
	static GFX::Bitmap rpar = {5, 7, 2, NULL, data_rpar};

	static uint8_t data_star[5] = {0x8a, 0x28, 0x00, 0x00, 0x00};
	static GFX::Bitmap star = {5, 7, 2, NULL, data_star};

	static uint8_t data_plus[5] = {0x80, 0x90, 0x4f, 0x08, 0x00};
	static GFX::Bitmap plus = {5, 7, 2, NULL, data_plus};

	static uint8_t data_comma[5] = {0x00, 0x00, 0x00, 0x44, 0x00};
	static GFX::Bitmap comma = {5, 7, 2, NULL, data_comma};

	static uint8_t data_minus[5] = {0x00, 0x80, 0x0f, 0x00, 0x00};
	static GFX::Bitmap minus = {5, 7, 2, NULL, data_minus};

	static uint8_t data_period[5] = {0x00, 0x00, 0x00, 0x40, 0x00};
	static GFX::Bitmap period = {5, 7, 2, NULL, data_period};

	static uint8_t data_fslash[5] = {0x10, 0x21, 0x22, 0x44, 0x00};
	static GFX::Bitmap fslash = {5, 7, 2, NULL, data_fslash};

	static uint8_t data_colon[5] = {0x00, 0x10, 0x00, 0x08, 0x00};
	static GFX::Bitmap colon = {5, 7, 2, NULL, data_colon};

	static uint8_t data_semicolon[5] = {0x00, 0x10, 0x00, 0x88, 0x00};
	static GFX::Bitmap semicolon = {5, 7, 2, NULL, data_semicolon};

	static uint8_t data_less[5] = {0x10, 0x11, 0x41, 0x10, 0x04};
	static GFX::Bitmap less = {5, 7, 2, NULL, data_less};

	static uint8_t data_equal[5] = {0x00, 0x7c, 0xf0, 0x01, 0x00};
	static GFX::Bitmap equal = {5, 7, 2, NULL, data_equal};

	static uint8_t data_greater[5] = {0x41, 0x10, 0x44, 0x44, 0x00};
	static GFX::Bitmap greater = {5, 7, 2, NULL, data_greater};

	static uint8_t data_question[5] = {0x2e, 0x22, 0x42, 0x00, 0x01};
	static GFX::Bitmap question = {5, 7, 2, NULL, data_question};

	static uint8_t data_at[5] = {0x2e, 0xd6, 0xda, 0x83, 0x03};
	static GFX::Bitmap at = {5, 7, 2, NULL, data_at};

	static uint8_t data_lsquare[5] = {0x9c, 0x10, 0x42, 0x08, 0x07};
	static GFX::Bitmap lsquare = {5, 7, 2, NULL, data_lsquare};

	static uint8_t data_bslash[5] = {0x41, 0x08, 0x82, 0x10, 0x04};
	static GFX::Bitmap bslash = {5, 7, 2, NULL, data_bslash};

	static uint8_t data_rsquare[5] = {0x87, 0x10, 0x42, 0xc8, 0x01};
	static GFX::Bitmap rsquare = {5, 7, 2, NULL, data_rsquare};

	static uint8_t data_carrot[5] = {0x44, 0x45, 0x00, 0x00, 0x00};
	static GFX::Bitmap carrot = {5, 7, 2, NULL, data_carrot};

	static uint8_t data_under[5] = {0x00, 0x00, 0x00, 0xc0, 0x07};
	static GFX::Bitmap under = {5, 7, 2, NULL, data_under};

	static uint8_t data_accent[5] = {0x41, 0x00, 0x00, 0x00, 0x00};
	static GFX::Bitmap accent = {5, 7, 2, NULL, data_accent};

	static uint8_t data_lcurly[5] = {0x98, 0x20, 0x82, 0x08, 0x06};
	static GFX::Bitmap lcurly = {5, 7, 2, NULL, data_lcurly};

	static uint8_t data_pipe[5] = {0x84, 0x10, 0x42, 0x08, 0x01};
	static GFX::Bitmap pipe = {5, 7, 2, NULL, data_pipe};

	static uint8_t data_rcurly[5] = {0x83, 0x08, 0x22, 0xc8, 0x00};
	static GFX::Bitmap rcurly = {5, 7, 2, NULL, data_rcurly};

	static uint8_t data_tilde[5] = {0x45, 0x01, 0x00, 0x00, 0x00};
	static GFX::Bitmap tilde = {5, 7, 2, NULL, data_tilde};

	static uint8_t data_Dino[4] = {0x3f, 0xee, 0xf8, 0x01};
	static GFX::Bitmap Dino = {5, 5, 2, NULL, data_Dino};

	static uint8_t data_Cactus[4] = {0x84, 0xd6, 0x4f, 0x08};
	static GFX::Bitmap Cactus = {5, 6, 2, NULL, data_Cactus};

	static uint8_t data_UFO[3] = {0x1c, 0xd1, 0x1f};
	static GFX::Bitmap UFO = {7, 3, 2, NULL, data_UFO};

	static uint32_t palette_Snake_Menu[3] = {0x000000, 0x00FF00, 0xFF0000};
	static uint8_t data_Snake_Menu[24] = {0x00, 0x00, 0x00, 0x50, 0x15, 0x00, 0x10, 0x10, 0x10, 0x14, 0x50, 0x15, 0x04, 0x00, 0x00, 0x14, 0x55, 0x01, 0x10, 0x01, 0x95, 0x50, 0x01, 0x00};
	static GFX::Bitmap Snake_Menu = {12, 8, 3, palette_Snake_Menu, data_Snake_Menu};

}

namespace Font {

	static GFX::Bitmap* font_5x7[128] = {&(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::space), &(Bitmaps::exclimation), &(Bitmaps::dquote), &(Bitmaps::hashtag), &(Bitmaps::dollar), &(Bitmaps::precent), &(Bitmaps::and_sym), &(Bitmaps::squote), &(Bitmaps::lpar), &(Bitmaps::rpar), &(Bitmaps::star), &(Bitmaps::plus), &(Bitmaps::comma), &(Bitmaps::minus), &(Bitmaps::period), &(Bitmaps::fslash), &(Bitmaps::n0), &(Bitmaps::n1), &(Bitmaps::n2), &(Bitmaps::n3), &(Bitmaps::n4), &(Bitmaps::n5), &(Bitmaps::n6), &(Bitmaps::n7), &(Bitmaps::n8), &(Bitmaps::n9), &(Bitmaps::colon), &(Bitmaps::semicolon), &(Bitmaps::less), &(Bitmaps::equal), &(Bitmaps::greater), &(Bitmaps::question), &(Bitmaps::at), &(Bitmaps::A), &(Bitmaps::B), &(Bitmaps::C), &(Bitmaps::D), &(Bitmaps::E), &(Bitmaps::F), &(Bitmaps::G), &(Bitmaps::H), &(Bitmaps::I), &(Bitmaps::J), &(Bitmaps::K), &(Bitmaps::L), &(Bitmaps::M), &(Bitmaps::N), &(Bitmaps::O), &(Bitmaps::P), &(Bitmaps::Q), &(Bitmaps::R), &(Bitmaps::S), &(Bitmaps::T), &(Bitmaps::U), &(Bitmaps::V), &(Bitmaps::W), &(Bitmaps::X), &(Bitmaps::Y), &(Bitmaps::Z), &(Bitmaps::lsquare), &(Bitmaps::bslash), &(Bitmaps::rsquare), &(Bitmaps::carrot), &(Bitmaps::under), &(Bitmaps::accent), &(Bitmaps::a), &(Bitmaps::b), &(Bitmaps::c), &(Bitmaps::d), &(Bitmaps::e), &(Bitmaps::f), &(Bitmaps::g), &(Bitmaps::h), &(Bitmaps::i), &(Bitmaps::j), &(Bitmaps::k), &(Bitmaps::l), &(Bitmaps::m), &(Bitmaps::n), &(Bitmaps::o), &(Bitmaps::p), &(Bitmaps::q), &(Bitmaps::r), &(Bitmaps::s), &(Bitmaps::t), &(Bitmaps::u), &(Bitmaps::v), &(Bitmaps::w), &(Bitmaps::x), &(Bitmaps::y), &(Bitmaps::z), &(Bitmaps::lcurly), &(Bitmaps::pipe), &(Bitmaps::rcurly), &(Bitmaps::tilde), &(Bitmaps::space)};

}

#pragma GCC diagnostic pop

#endif
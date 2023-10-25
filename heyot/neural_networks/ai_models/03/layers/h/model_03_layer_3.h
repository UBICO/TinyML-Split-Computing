#pragma once

#include <cstdint>

const uint8_t mod_3[] = {
28, 0, 0, 0, 84, 70, 76, 51, 20, 0, 32, 0, 28, 0, 24, 0, 20, 0, 16, 0, 12, 0, 0, 0, 8, 0, 4, 0, 20, 0, 0, 0, 28, 0, 0, 0, 156, 0, 0, 0, 244, 0, 0, 0, 248, 3, 0, 0, 8, 4, 0, 0, 72, 6, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 0, 0, 10, 0, 16, 0, 12, 0, 8, 0, 4, 0, 10, 0, 0, 0, 12, 0, 0, 0, 28, 0, 0, 0, 60, 0, 0, 0, 15, 0, 0, 0, 115, 101, 114, 118, 105, 110, 103, 95, 100, 101, 102, 97, 117, 108, 116, 0, 1, 0, 0, 0, 4, 0, 0, 0, 140, 255, 255, 255, 3, 0, 0, 0, 4, 0, 0, 0, 10, 0, 0, 0, 110, 110, 95, 108, 97, 121, 101, 114, 95, 52, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 214, 252, 255, 255, 4, 0, 0, 0, 16, 0, 0, 0, 110, 110, 95, 108, 97, 121, 101, 114, 95, 52, 95, 105, 110, 112, 117, 116, 0, 0, 0, 0, 2, 0, 0, 0, 52, 0, 0, 0, 4, 0, 0, 0, 220, 255, 255, 255, 6, 0, 0, 0, 4, 0, 0, 0, 19, 0, 0, 0, 67, 79, 78, 86, 69, 82, 83, 73, 79, 78, 95, 77, 69, 84, 65, 68, 65, 84, 65, 0, 8, 0, 12, 0, 8, 0, 4, 0, 8, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 19, 0, 0, 0, 109, 105, 110, 95, 114, 117, 110, 116, 105, 109, 101, 95, 118, 101, 114, 115, 105, 111, 110, 0, 7, 0, 0, 0, 0, 3, 0, 0, 248, 2, 0, 0, 168, 2, 0, 0, 144, 0, 0, 0, 136, 0, 0, 0, 104, 0, 0, 0, 4, 0, 0, 0, 114, 253, 255, 255, 4, 0, 0, 0, 84, 0, 0, 0, 12, 0, 0, 0, 8, 0, 14, 0, 8, 0, 4, 0, 8, 0, 0, 0, 16, 0, 0, 0, 36, 0, 0, 0, 0, 0, 6, 0, 8, 0, 4, 0, 6, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 16, 0, 12, 0, 8, 0, 4, 0, 10, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 6, 0, 0, 0, 50, 46, 49, 51, 46, 48, 0, 0, 210, 253, 255, 255, 4, 0, 0, 0, 16, 0, 0, 0, 49, 46, 53, 46, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 251, 255, 255, 242, 253, 255, 255, 4, 0, 0, 0, 0, 2, 0, 0, 176, 241, 190, 189, 32, 46, 73, 62, 32, 177, 149, 190, 192, 44, 216, 189, 224, 214, 23, 62, 96, 115, 71, 61, 16, 227, 46, 190, 64, 107, 242, 190, 132, 38, 199, 190, 224, 52, 65, 190, 128, 39, 12, 189, 188, 119, 179, 62, 131, 126, 230, 64, 248, 108, 161, 62, 29, 1, 180, 190, 240, 28, 221, 64, 8, 137, 167, 62, 104, 46, 127, 190, 248, 50, 85, 62, 64, 95, 136, 60, 188, 152, 249, 190, 176, 252, 229, 62, 128, 172, 31, 190, 96, 35, 4, 62, 244, 197, 131, 62, 56, 119, 222, 190, 104, 107, 114, 62, 56, 163, 118, 190, 137, 232, 223, 64, 128, 57, 192, 188, 131, 146, 222, 62, 226, 133, 234, 64, 160, 123, 212, 61, 144, 150, 60, 190, 196, 242, 132, 62, 80, 148, 36, 62, 16, 112, 83, 190, 168, 6, 103, 62, 224, 220, 209, 189, 192, 196, 194, 189, 68, 165, 254, 190, 220, 55, 246, 62, 192, 90, 124, 61, 0, 123, 52, 61, 32, 190, 61, 190, 112, 154, 179, 189, 0, 9, 129, 188, 0, 98, 57, 61, 156, 212, 160, 190, 160, 157, 200, 189, 88, 255, 250, 190, 160, 195, 129, 189, 52, 241, 228, 64, 204, 27, 141, 190, 174, 235, 196, 189, 255, 240, 236, 64, 120, 147, 163, 190, 236, 183, 249, 190, 40, 243, 185, 62, 8, 148, 168, 62, 16, 176, 235, 190, 240, 234, 197, 190, 104, 77, 128, 190, 0, 51, 86, 60, 208, 53, 184, 61, 232, 215, 18, 190, 48, 153, 155, 61, 52, 149, 209, 190, 2, 180, 214, 64, 64, 196, 149, 189, 169, 112, 213, 189, 181, 158, 230, 64, 168, 224, 125, 62, 64, 49, 12, 190, 40, 0, 223, 190, 36, 47, 185, 62, 186, 6, 225, 64, 80, 20, 148, 61, 97, 169, 178, 60, 50, 139, 228, 64, 12, 138, 249, 62, 144, 138, 147, 190, 224, 247, 113, 189, 28, 24, 152, 190, 20, 157, 49, 190, 128, 154, 147, 188, 38, 113, 214, 190, 91, 171, 31, 62, 40, 128, 172, 62, 0, 147, 154, 62, 0, 60, 213, 58, 160, 111, 156, 190, 150, 44, 229, 64, 112, 211, 226, 189, 114, 7, 18, 63, 48, 196, 224, 64, 24, 216, 227, 190, 72, 180, 226, 190, 160, 246, 174, 61, 64, 121, 221, 188, 150, 159, 200, 190, 160, 210, 192, 62, 231, 115, 236, 62, 89, 85, 85, 188, 64, 89, 164, 189, 204, 219, 170, 190, 96, 162, 14, 189, 232, 73, 79, 62, 35, 194, 228, 64, 108, 112, 179, 190, 202, 149, 180, 190, 25, 71, 233, 64, 192, 84, 195, 61, 128, 250, 250, 62, 100, 105, 230, 62, 160, 191, 122, 190, 16, 4, 173, 189, 196, 77, 167, 190, 160, 141, 17, 190, 128, 222, 56, 60, 4, 160, 178, 62, 176, 72, 189, 190, 220, 95, 143, 62, 240, 163, 18, 190, 128, 108, 4, 59, 32, 152, 255, 190, 239, 246, 118, 62, 85, 177, 19, 189, 0, 0, 6, 0, 8, 0, 4, 0, 6, 0, 0, 0, 4, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 87, 156, 192, 64, 0, 0, 0, 0, 145, 212, 192, 64, 0, 0, 0, 0, 0, 0, 0, 0, 139, 213, 192, 64, 0, 0, 0, 0, 127, 54, 190, 64, 118, 190, 192, 64, 130, 156, 89, 189, 186, 3, 193, 64, 125, 21, 148, 59, 0, 84, 192, 64, 0, 0, 0, 0, 254, 56, 152, 189, 220, 253, 255, 255, 224, 253, 255, 255, 15, 0, 0, 0, 77, 76, 73, 82, 32, 67, 111, 110, 118, 101, 114, 116, 101, 100, 46, 0, 1, 0, 0, 0, 20, 0, 0, 0, 0, 0, 14, 0, 24, 0, 20, 0, 16, 0, 12, 0, 8, 0, 4, 0, 14, 0, 0, 0, 20, 0, 0, 0, 28, 0, 0, 0, 108, 0, 0, 0, 112, 0, 0, 0, 116, 0, 0, 0, 4, 0, 0, 0, 109, 97, 105, 110, 0, 0, 0, 0, 1, 0, 0, 0, 20, 0, 0, 0, 0, 0, 14, 0, 22, 0, 0, 0, 16, 0, 12, 0, 11, 0, 4, 0, 14, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 8, 24, 0, 0, 0, 28, 0, 0, 0, 0, 0, 6, 0, 8, 0, 7, 0, 6, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 60, 1, 0, 0, 200, 0, 0, 0, 96, 0, 0, 0, 4, 0, 0, 0, 234, 254, 255, 255, 0, 0, 0, 1, 20, 0, 0, 0, 28, 0, 0, 0, 28, 0, 0, 0, 4, 0, 0, 0, 52, 0, 0, 0, 2, 0, 0, 0, 255, 255, 255, 255, 16, 0, 0, 0, 212, 254, 255, 255, 25, 0, 0, 0, 83, 116, 97, 116, 101, 102, 117, 108, 80, 97, 114, 116, 105, 116, 105, 111, 110, 101, 100, 67, 97, 108, 108, 58, 48, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 178, 255, 255, 255, 0, 0, 0, 1, 16, 0, 0, 0, 16, 0, 0, 0, 3, 0, 0, 0, 44, 0, 0, 0, 28, 255, 255, 255, 31, 0, 0, 0, 115, 101, 113, 117, 101, 110, 116, 105, 97, 108, 95, 49, 55, 47, 110, 110, 95, 108, 97, 121, 101, 114, 95, 52, 47, 77, 97, 116, 77, 117, 108, 0, 2, 0, 0, 0, 16, 0, 0, 0, 8, 0, 0, 0, 0, 0, 22, 0, 24, 0, 20, 0, 0, 0, 16, 0, 12, 0, 8, 0, 0, 0, 0, 0, 0, 0, 7, 0, 22, 0, 0, 0, 0, 0, 0, 1, 16, 0, 0, 0, 16, 0, 0, 0, 2, 0, 0, 0, 60, 0, 0, 0, 128, 255, 255, 255, 47, 0, 0, 0, 115, 101, 113, 117, 101, 110, 116, 105, 97, 108, 95, 49, 55, 47, 110, 110, 95, 108, 97, 121, 101, 114, 95, 52, 47, 66, 105, 97, 115, 65, 100, 100, 47, 82, 101, 97, 100, 86, 97, 114, 105, 97, 98, 108, 101, 79, 112, 0, 1, 0, 0, 0, 16, 0, 0, 0, 0, 0, 22, 0, 28, 0, 24, 0, 0, 0, 20, 0, 16, 0, 12, 0, 0, 0, 0, 0, 8, 0, 7, 0, 22, 0, 0, 0, 0, 0, 0, 1, 20, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 1, 0, 0, 0, 64, 0, 0, 0, 2, 0, 0, 0, 255, 255, 255, 255, 8, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 34, 0, 0, 0, 115, 101, 114, 118, 105, 110, 103, 95, 100, 101, 102, 97, 117, 108, 116, 95, 110, 110, 95, 108, 97, 121, 101, 114, 95, 52, 95, 105, 110, 112, 117, 116, 58, 48, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 12, 0, 12, 0, 11, 0, 0, 0, 0, 0, 4, 0, 12, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 9
};
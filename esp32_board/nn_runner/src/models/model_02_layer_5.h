#pragma once

#include <cstdint>

const uint8_t mod_5[] = {
28, 0, 0, 0, 84, 70, 76, 51, 20, 0, 32, 0, 28, 0, 24, 0, 20, 0, 16, 0, 12, 0, 0, 0, 8, 0, 4, 0, 20, 0, 0, 0, 28, 0, 0, 0, 156, 0, 0, 0, 244, 0, 0, 0, 216, 3, 0, 0, 232, 3, 0, 0, 40, 6, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 0, 0, 10, 0, 16, 0, 12, 0, 8, 0, 4, 0, 10, 0, 0, 0, 12, 0, 0, 0, 28, 0, 0, 0, 60, 0, 0, 0, 15, 0, 0, 0, 115, 101, 114, 118, 105, 110, 103, 95, 100, 101, 102, 97, 117, 108, 116, 0, 1, 0, 0, 0, 4, 0, 0, 0, 140, 255, 255, 255, 3, 0, 0, 0, 4, 0, 0, 0, 10, 0, 0, 0, 110, 110, 95, 108, 97, 121, 101, 114, 95, 54, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 214, 252, 255, 255, 4, 0, 0, 0, 16, 0, 0, 0, 110, 110, 95, 108, 97, 121, 101, 114, 95, 54, 95, 105, 110, 112, 117, 116, 0, 0, 0, 0, 2, 0, 0, 0, 52, 0, 0, 0, 4, 0, 0, 0, 220, 255, 255, 255, 6, 0, 0, 0, 4, 0, 0, 0, 19, 0, 0, 0, 67, 79, 78, 86, 69, 82, 83, 73, 79, 78, 95, 77, 69, 84, 65, 68, 65, 84, 65, 0, 8, 0, 12, 0, 8, 0, 4, 0, 8, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 19, 0, 0, 0, 109, 105, 110, 95, 114, 117, 110, 116, 105, 109, 101, 95, 118, 101, 114, 115, 105, 111, 110, 0, 7, 0, 0, 0, 224, 2, 0, 0, 216, 2, 0, 0, 168, 2, 0, 0, 144, 0, 0, 0, 136, 0, 0, 0, 104, 0, 0, 0, 4, 0, 0, 0, 114, 253, 255, 255, 4, 0, 0, 0, 84, 0, 0, 0, 12, 0, 0, 0, 8, 0, 14, 0, 8, 0, 4, 0, 8, 0, 0, 0, 16, 0, 0, 0, 36, 0, 0, 0, 0, 0, 6, 0, 8, 0, 4, 0, 6, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 16, 0, 12, 0, 8, 0, 4, 0, 10, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 6, 0, 0, 0, 50, 46, 49, 51, 46, 48, 0, 0, 210, 253, 255, 255, 4, 0, 0, 0, 16, 0, 0, 0, 49, 46, 53, 46, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 251, 255, 255, 242, 253, 255, 255, 4, 0, 0, 0, 0, 2, 0, 0, 8, 146, 208, 190, 64, 204, 214, 189, 212, 25, 159, 190, 208, 10, 238, 61, 128, 130, 51, 190, 48, 228, 233, 189, 112, 252, 13, 62, 32, 130, 45, 61, 152, 214, 130, 190, 160, 192, 80, 61, 208, 81, 223, 62, 212, 158, 178, 62, 168, 134, 44, 190, 92, 143, 149, 62, 16, 124, 196, 190, 192, 3, 212, 61, 101, 49, 131, 189, 213, 246, 37, 62, 110, 66, 185, 190, 82, 44, 233, 189, 97, 166, 210, 62, 168, 243, 251, 62, 217, 147, 165, 62, 24, 113, 127, 190, 12, 83, 180, 190, 114, 168, 34, 62, 192, 167, 245, 189, 64, 144, 251, 189, 176, 187, 98, 62, 0, 173, 246, 189, 168, 76, 138, 62, 88, 173, 62, 190, 128, 75, 6, 61, 200, 253, 139, 190, 176, 80, 227, 189, 176, 150, 95, 62, 0, 128, 206, 59, 8, 180, 11, 62, 128, 250, 60, 189, 64, 197, 245, 188, 60, 216, 216, 62, 252, 34, 139, 190, 128, 197, 182, 60, 148, 250, 187, 62, 176, 86, 120, 190, 160, 43, 198, 62, 132, 243, 184, 62, 128, 240, 228, 62, 228, 128, 49, 61, 140, 55, 252, 62, 178, 113, 67, 190, 7, 254, 126, 190, 125, 116, 58, 190, 0, 33, 55, 62, 182, 61, 143, 60, 162, 255, 252, 62, 84, 139, 246, 62, 194, 190, 126, 62, 144, 224, 122, 62, 84, 171, 204, 62, 16, 45, 135, 189, 152, 95, 177, 62, 112, 159, 140, 62, 176, 83, 198, 62, 232, 231, 15, 190, 152, 71, 54, 190, 176, 177, 19, 190, 128, 73, 120, 189, 36, 148, 243, 190, 0, 208, 206, 57, 108, 80, 222, 190, 96, 43, 51, 189, 0, 174, 151, 190, 0, 250, 168, 62, 144, 58, 218, 61, 48, 147, 192, 61, 232, 186, 31, 190, 128, 244, 253, 61, 80, 163, 239, 190, 112, 116, 24, 62, 162, 35, 136, 62, 124, 109, 39, 189, 67, 125, 118, 62, 100, 195, 62, 190, 5, 114, 143, 62, 92, 54, 11, 61, 168, 183, 51, 62, 230, 155, 226, 62, 8, 105, 104, 190, 251, 131, 209, 190, 12, 116, 246, 190, 84, 114, 240, 62, 228, 223, 139, 190, 64, 119, 16, 61, 192, 75, 1, 62, 104, 139, 75, 190, 128, 161, 117, 61, 216, 247, 49, 190, 96, 175, 27, 62, 192, 92, 145, 61, 160, 96, 54, 190, 192, 46, 253, 190, 116, 80, 151, 190, 16, 20, 235, 61, 0, 54, 182, 189, 204, 40, 143, 190, 212, 182, 247, 62, 104, 154, 2, 62, 128, 114, 130, 188, 144, 122, 172, 61, 200, 125, 239, 190, 0, 193, 80, 61, 116, 199, 205, 190, 80, 26, 4, 190, 48, 90, 167, 61, 60, 241, 137, 190, 184, 153, 9, 190, 56, 38, 14, 190, 72, 141, 192, 190, 0, 185, 184, 60, 192, 168, 114, 190, 160, 147, 237, 190, 192, 219, 141, 61, 48, 139, 136, 190, 176, 220, 220, 190, 40, 239, 136, 190, 0, 172, 163, 186, 64, 199, 219, 62, 0, 0, 6, 0, 8, 0, 4, 0, 6, 0, 0, 0, 4, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 114, 201, 196, 187, 0, 0, 0, 0, 118, 201, 196, 59, 0, 0, 0, 0, 116, 201, 196, 187, 0, 0, 0, 0, 0, 0, 0, 0, 220, 253, 255, 255, 224, 253, 255, 255, 15, 0, 0, 0, 77, 76, 73, 82, 32, 67, 111, 110, 118, 101, 114, 116, 101, 100, 46, 0, 1, 0, 0, 0, 20, 0, 0, 0, 0, 0, 14, 0, 24, 0, 20, 0, 16, 0, 12, 0, 8, 0, 4, 0, 14, 0, 0, 0, 20, 0, 0, 0, 28, 0, 0, 0, 108, 0, 0, 0, 112, 0, 0, 0, 116, 0, 0, 0, 4, 0, 0, 0, 109, 97, 105, 110, 0, 0, 0, 0, 1, 0, 0, 0, 20, 0, 0, 0, 0, 0, 14, 0, 22, 0, 0, 0, 16, 0, 12, 0, 11, 0, 4, 0, 14, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 8, 24, 0, 0, 0, 28, 0, 0, 0, 0, 0, 6, 0, 8, 0, 7, 0, 6, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 60, 1, 0, 0, 200, 0, 0, 0, 96, 0, 0, 0, 4, 0, 0, 0, 234, 254, 255, 255, 0, 0, 0, 1, 20, 0, 0, 0, 28, 0, 0, 0, 28, 0, 0, 0, 4, 0, 0, 0, 52, 0, 0, 0, 2, 0, 0, 0, 255, 255, 255, 255, 8, 0, 0, 0, 212, 254, 255, 255, 25, 0, 0, 0, 83, 116, 97, 116, 101, 102, 117, 108, 80, 97, 114, 116, 105, 116, 105, 111, 110, 101, 100, 67, 97, 108, 108, 58, 48, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, 178, 255, 255, 255, 0, 0, 0, 1, 16, 0, 0, 0, 16, 0, 0, 0, 3, 0, 0, 0, 44, 0, 0, 0, 28, 255, 255, 255, 31, 0, 0, 0, 115, 101, 113, 117, 101, 110, 116, 105, 97, 108, 95, 49, 48, 47, 110, 110, 95, 108, 97, 121, 101, 114, 95, 54, 47, 77, 97, 116, 77, 117, 108, 0, 2, 0, 0, 0, 8, 0, 0, 0, 16, 0, 0, 0, 0, 0, 22, 0, 24, 0, 20, 0, 0, 0, 16, 0, 12, 0, 8, 0, 0, 0, 0, 0, 0, 0, 7, 0, 22, 0, 0, 0, 0, 0, 0, 1, 16, 0, 0, 0, 16, 0, 0, 0, 2, 0, 0, 0, 60, 0, 0, 0, 128, 255, 255, 255, 47, 0, 0, 0, 115, 101, 113, 117, 101, 110, 116, 105, 97, 108, 95, 49, 48, 47, 110, 110, 95, 108, 97, 121, 101, 114, 95, 54, 47, 66, 105, 97, 115, 65, 100, 100, 47, 82, 101, 97, 100, 86, 97, 114, 105, 97, 98, 108, 101, 79, 112, 0, 1, 0, 0, 0, 8, 0, 0, 0, 0, 0, 22, 0, 28, 0, 24, 0, 0, 0, 20, 0, 16, 0, 12, 0, 0, 0, 0, 0, 8, 0, 7, 0, 22, 0, 0, 0, 0, 0, 0, 1, 20, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 1, 0, 0, 0, 64, 0, 0, 0, 2, 0, 0, 0, 255, 255, 255, 255, 16, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 34, 0, 0, 0, 115, 101, 114, 118, 105, 110, 103, 95, 100, 101, 102, 97, 117, 108, 116, 95, 110, 110, 95, 108, 97, 121, 101, 114, 95, 54, 95, 105, 110, 112, 117, 116, 58, 48, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 12, 0, 12, 0, 11, 0, 0, 0, 0, 0, 4, 0, 12, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 9
};
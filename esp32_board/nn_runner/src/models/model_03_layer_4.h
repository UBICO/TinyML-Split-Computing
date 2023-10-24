#pragma once

#include <cstdint>

const uint8_t mod_4[] = {
28, 0, 0, 0, 84, 70, 76, 51, 20, 0, 32, 0, 28, 0, 24, 0, 20, 0, 16, 0, 12, 0, 0, 0, 8, 0, 4, 0, 20, 0, 0, 0, 28, 0, 0, 0, 156, 0, 0, 0, 244, 0, 0, 0, 56, 10, 0, 0, 72, 10, 0, 0, 136, 12, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 0, 0, 10, 0, 16, 0, 12, 0, 8, 0, 4, 0, 10, 0, 0, 0, 12, 0, 0, 0, 28, 0, 0, 0, 60, 0, 0, 0, 15, 0, 0, 0, 115, 101, 114, 118, 105, 110, 103, 95, 100, 101, 102, 97, 117, 108, 116, 0, 1, 0, 0, 0, 4, 0, 0, 0, 140, 255, 255, 255, 3, 0, 0, 0, 4, 0, 0, 0, 10, 0, 0, 0, 110, 110, 95, 108, 97, 121, 101, 114, 95, 53, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 214, 246, 255, 255, 4, 0, 0, 0, 16, 0, 0, 0, 110, 110, 95, 108, 97, 121, 101, 114, 95, 53, 95, 105, 110, 112, 117, 116, 0, 0, 0, 0, 2, 0, 0, 0, 52, 0, 0, 0, 4, 0, 0, 0, 220, 255, 255, 255, 6, 0, 0, 0, 4, 0, 0, 0, 19, 0, 0, 0, 67, 79, 78, 86, 69, 82, 83, 73, 79, 78, 95, 77, 69, 84, 65, 68, 65, 84, 65, 0, 8, 0, 12, 0, 8, 0, 4, 0, 8, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 19, 0, 0, 0, 109, 105, 110, 95, 114, 117, 110, 116, 105, 109, 101, 95, 118, 101, 114, 115, 105, 111, 110, 0, 7, 0, 0, 0, 64, 9, 0, 0, 56, 9, 0, 0, 168, 8, 0, 0, 144, 0, 0, 0, 136, 0, 0, 0, 104, 0, 0, 0, 4, 0, 0, 0, 114, 247, 255, 255, 4, 0, 0, 0, 84, 0, 0, 0, 12, 0, 0, 0, 8, 0, 14, 0, 8, 0, 4, 0, 8, 0, 0, 0, 16, 0, 0, 0, 36, 0, 0, 0, 0, 0, 6, 0, 8, 0, 4, 0, 6, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 16, 0, 12, 0, 8, 0, 4, 0, 10, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 6, 0, 0, 0, 50, 46, 49, 51, 46, 48, 0, 0, 210, 247, 255, 255, 4, 0, 0, 0, 16, 0, 0, 0, 49, 46, 53, 46, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 245, 255, 255, 242, 247, 255, 255, 4, 0, 0, 0, 0, 8, 0, 0, 232, 156, 20, 62, 164, 31, 227, 64, 240, 49, 50, 61, 233, 168, 222, 64, 8, 190, 225, 61, 120, 111, 250, 61, 108, 136, 211, 64, 8, 34, 40, 189, 196, 46, 216, 64, 133, 235, 229, 64, 120, 192, 145, 62, 156, 54, 219, 64, 96, 98, 46, 189, 19, 36, 230, 64, 32, 174, 108, 61, 42, 117, 145, 190, 164, 21, 180, 189, 197, 113, 229, 64, 2, 91, 110, 190, 37, 127, 228, 64, 60, 19, 192, 61, 22, 8, 120, 190, 59, 83, 226, 64, 90, 195, 106, 62, 119, 246, 230, 64, 14, 122, 213, 64, 163, 62, 73, 62, 184, 145, 209, 64, 199, 158, 146, 190, 132, 173, 221, 64, 50, 24, 253, 189, 48, 125, 156, 188, 130, 117, 120, 62, 45, 117, 79, 190, 192, 208, 246, 188, 211, 37, 96, 190, 3, 56, 173, 190, 94, 149, 121, 62, 252, 96, 211, 189, 208, 216, 133, 188, 30, 44, 62, 62, 141, 26, 137, 62, 192, 168, 177, 188, 22, 95, 166, 190, 143, 169, 169, 190, 237, 228, 78, 190, 80, 255, 202, 61, 122, 207, 1, 190, 247, 243, 59, 190, 69, 143, 230, 64, 241, 219, 154, 62, 91, 141, 226, 64, 254, 210, 90, 62, 55, 0, 33, 190, 193, 122, 228, 64, 207, 136, 148, 62, 128, 20, 230, 64, 30, 252, 222, 64, 244, 113, 237, 61, 123, 54, 225, 64, 69, 252, 175, 62, 162, 148, 215, 64, 184, 218, 139, 189, 174, 135, 159, 189, 191, 222, 47, 190, 160, 188, 17, 190, 250, 173, 38, 62, 198, 189, 171, 190, 51, 65, 157, 62, 29, 20, 167, 62, 85, 87, 95, 61, 160, 49, 136, 190, 92, 175, 195, 188, 199, 117, 4, 190, 19, 202, 44, 62, 196, 113, 140, 61, 208, 129, 221, 61, 118, 247, 171, 62, 226, 55, 7, 62, 217, 204, 102, 62, 34, 230, 174, 190, 198, 227, 220, 64, 170, 215, 105, 62, 141, 207, 229, 64, 128, 123, 242, 188, 88, 162, 185, 61, 44, 68, 229, 64, 176, 239, 159, 189, 142, 180, 224, 64, 49, 227, 225, 64, 200, 63, 112, 190, 186, 34, 210, 64, 212, 107, 58, 62, 97, 40, 218, 64, 254, 239, 100, 62, 186, 252, 38, 190, 131, 240, 85, 190, 206, 54, 226, 189, 83, 235, 168, 190, 88, 214, 37, 61, 128, 232, 142, 190, 118, 69, 122, 190, 249, 185, 134, 190, 35, 212, 167, 62, 63, 231, 179, 62, 193, 248, 148, 190, 112, 189, 30, 189, 176, 228, 111, 190, 215, 195, 145, 62, 21, 46, 154, 190, 136, 219, 16, 190, 169, 166, 132, 190, 88, 49, 135, 61, 219, 243, 223, 64, 116, 235, 227, 61, 230, 100, 224, 64, 237, 238, 170, 190, 197, 84, 56, 190, 26, 70, 213, 64, 74, 46, 216, 189, 228, 93, 210, 64, 189, 26, 226, 64, 161, 152, 213, 188, 195, 31, 225, 64, 242, 80, 162, 61, 169, 79, 231, 64, 169, 135, 172, 62, 235, 228, 70, 190, 16, 120, 231, 60, 54, 84, 219, 64, 11, 179, 178, 62, 216, 180, 224, 64, 151, 104, 178, 190, 0, 96, 31, 188, 34, 106, 224, 64, 14, 91, 170, 190, 120, 72, 212, 64, 249, 132, 225, 64, 243, 198, 122, 190, 77, 6, 224, 64, 56, 209, 66, 189, 211, 251, 210, 64, 200, 182, 180, 190, 224, 216, 229, 189, 59, 189, 176, 62, 146, 17, 216, 64, 107, 138, 130, 62, 108, 105, 224, 64, 12, 62, 244, 189, 204, 123, 182, 61, 69, 214, 222, 64, 2, 167, 228, 189, 253, 98, 232, 64, 1, 116, 220, 64, 67, 125, 134, 190, 125, 79, 229, 64, 162, 141, 101, 62, 80, 118, 227, 64, 175, 185, 23, 190, 21, 50, 238, 188, 71, 153, 0, 190, 146, 219, 212, 64, 44, 234, 17, 62, 172, 143, 223, 64, 71, 36, 71, 190, 207, 19, 152, 62, 234, 18, 228, 64, 88, 193, 170, 189, 186, 141, 214, 64, 45, 202, 227, 64, 66, 214, 33, 62, 197, 14, 220, 64, 222, 13, 246, 189, 38, 183, 221, 64, 218, 29, 112, 62, 102, 89, 163, 187, 96, 27, 214, 60, 43, 231, 118, 190, 16, 22, 6, 61, 123, 62, 99, 62, 27, 15, 101, 190, 96, 60, 54, 188, 249, 94, 35, 61, 0, 23, 63, 59, 128, 110, 208, 61, 48, 239, 131, 62, 216, 9, 7, 189, 255, 93, 160, 190, 7, 128, 140, 62, 148, 245, 187, 189, 160, 137, 21, 61, 78, 215, 77, 62, 53, 189, 175, 62, 23, 64, 173, 190, 57, 148, 148, 62, 24, 124, 85, 189, 98, 124, 122, 62, 219, 126, 129, 62, 120, 60, 75, 189, 238, 174, 9, 62, 213, 53, 140, 190, 118, 72, 172, 190, 209, 253, 168, 62, 39, 98, 159, 62, 57, 19, 104, 190, 96, 2, 149, 189, 93, 134, 84, 190, 64, 162, 97, 190, 34, 138, 110, 62, 16, 181, 210, 64, 4, 149, 149, 190, 167, 254, 209, 64, 122, 93, 64, 62, 136, 28, 105, 189, 109, 53, 215, 64, 26, 46, 59, 62, 173, 2, 211, 64, 221, 65, 223, 64, 214, 218, 254, 189, 102, 57, 229, 64, 0, 102, 13, 187, 49, 85, 227, 64, 194, 105, 23, 190, 154, 84, 207, 61, 101, 82, 133, 62, 29, 11, 28, 190, 140, 214, 165, 190, 190, 127, 145, 190, 0, 101, 166, 60, 109, 213, 168, 190, 110, 126, 12, 62, 43, 38, 157, 62, 48, 93, 68, 189, 118, 58, 22, 62, 109, 161, 146, 62, 202, 28, 83, 62, 64, 7, 73, 60, 128, 248, 161, 190, 8, 159, 126, 189, 131, 13, 9, 190, 114, 69, 78, 62, 134, 122, 59, 62, 54, 129, 84, 62, 58, 158, 147, 190, 236, 173, 96, 190, 7, 158, 141, 62, 212, 79, 101, 190, 230, 11, 117, 62, 77, 253, 174, 190, 222, 38, 66, 62, 136, 64, 221, 189, 146, 2, 64, 190, 202, 186, 49, 62, 192, 76, 252, 60, 221, 13, 146, 62, 251, 235, 138, 62, 232, 172, 151, 61, 100, 25, 231, 64, 168, 162, 230, 61, 125, 4, 212, 64, 149, 104, 167, 62, 154, 209, 110, 190, 194, 191, 217, 64, 139, 224, 21, 190, 109, 55, 222, 64, 30, 167, 230, 64, 250, 198, 99, 190, 217, 119, 222, 64, 218, 179, 103, 62, 20, 222, 225, 64, 150, 13, 105, 62, 197, 144, 142, 190, 178, 118, 114, 62, 233, 46, 166, 62, 208, 190, 186, 188, 155, 109, 15, 61, 16, 0, 231, 60, 216, 113, 189, 61, 23, 18, 121, 190, 88, 50, 155, 61, 132, 60, 160, 190, 112, 92, 106, 62, 39, 213, 2, 190, 140, 42, 102, 62, 55, 196, 81, 62, 10, 63, 161, 190, 44, 215, 165, 189, 169, 20, 21, 62, 80, 168, 187, 60, 238, 46, 218, 64, 200, 39, 180, 190, 31, 204, 201, 64, 160, 186, 43, 188, 136, 247, 58, 189, 236, 59, 202, 64, 122, 80, 32, 190, 13, 151, 222, 64, 96, 182, 218, 64, 30, 43, 144, 190, 79, 253, 214, 64, 32, 227, 170, 190, 220, 121, 220, 64, 96, 66, 178, 60, 117, 65, 128, 62, 100, 88, 130, 190, 155, 47, 225, 64, 40, 234, 30, 189, 220, 149, 228, 64, 184, 107, 177, 189, 74, 75, 142, 190, 167, 242, 219, 64, 192, 127, 39, 189, 188, 113, 227, 64, 186, 117, 215, 64, 168, 43, 239, 58, 185, 84, 215, 64, 27, 34, 184, 62, 35, 88, 230, 64, 88, 144, 146, 190, 124, 161, 153, 62, 64, 96, 63, 60, 128, 184, 3, 187, 123, 146, 95, 190, 228, 151, 62, 190, 158, 64, 218, 189, 145, 68, 156, 190, 178, 44, 46, 62, 103, 180, 160, 62, 201, 55, 180, 62, 9, 245, 145, 190, 96, 87, 173, 60, 60, 183, 48, 190, 234, 224, 255, 189, 204, 177, 223, 61, 248, 102, 169, 190, 78, 87, 70, 190, 208, 245, 191, 60, 81, 50, 133, 190, 0, 240, 68, 61, 245, 145, 196, 189, 248, 144, 14, 61, 45, 48, 163, 62, 92, 217, 105, 188, 3, 38, 140, 190, 141, 22, 157, 62, 239, 33, 168, 190, 117, 185, 160, 62, 52, 125, 190, 189, 61, 215, 138, 62, 62, 143, 102, 62, 182, 131, 55, 62, 35, 133, 86, 190, 134, 132, 109, 62, 52, 155, 181, 61, 209, 114, 131, 62, 8, 159, 193, 61, 249, 159, 145, 62, 10, 226, 67, 62, 8, 114, 135, 190, 85, 206, 38, 190, 168, 245, 159, 190, 71, 21, 154, 190, 22, 68, 82, 62, 57, 75, 44, 190, 156, 35, 251, 189, 131, 153, 132, 62, 147, 157, 74, 190, 128, 218, 180, 187, 238, 123, 101, 62, 212, 189, 17, 62, 128, 111, 170, 61, 174, 24, 0, 189, 68, 88, 93, 190, 77, 36, 79, 190, 233, 197, 87, 189, 15, 97, 160, 62, 172, 168, 150, 190, 76, 162, 139, 190, 144, 68, 174, 61, 125, 7, 157, 62, 84, 175, 225, 61, 108, 69, 77, 190, 90, 240, 141, 190, 89, 221, 43, 190, 202, 167, 91, 62, 182, 146, 229, 64, 39, 186, 39, 190, 26, 199, 223, 64, 248, 30, 122, 190, 32, 151, 82, 190, 201, 235, 227, 64, 160, 252, 73, 60, 147, 98, 222, 64, 216, 94, 211, 64, 252, 107, 151, 62, 212, 251, 223, 64, 239, 144, 56, 62, 92, 132, 226, 64, 136, 224, 154, 61, 144, 180, 180, 60, 0, 54, 79, 189, 214, 6, 10, 62, 208, 90, 249, 61, 232, 131, 100, 189, 194, 177, 110, 62, 192, 246, 158, 59, 0, 216, 196, 57, 83, 163, 159, 62, 98, 45, 63, 62, 222, 142, 89, 190, 90, 239, 67, 62, 232, 80, 191, 189, 18, 213, 76, 190, 24, 226, 30, 61, 171, 139, 159, 190, 252, 214, 148, 189, 80, 79, 255, 60, 33, 0, 218, 64, 104, 155, 201, 61, 55, 146, 216, 64, 70, 123, 16, 190, 212, 104, 120, 190, 227, 247, 216, 64, 126, 159, 107, 62, 60, 41, 215, 64, 12, 58, 221, 64, 109, 203, 177, 62, 80, 5, 220, 64, 195, 174, 242, 61, 185, 18, 228, 64, 158, 203, 72, 62, 195, 210, 50, 188, 240, 39, 28, 189, 192, 67, 131, 61, 38, 222, 5, 62, 180, 49, 91, 62, 96, 84, 44, 60, 28, 34, 140, 190, 79, 176, 100, 190, 161, 176, 146, 190, 24, 202, 143, 190, 159, 254, 31, 62, 66, 253, 130, 190, 124, 43, 89, 190, 21, 19, 129, 62, 191, 46, 51, 190, 158, 23, 245, 189, 22, 124, 142, 61, 127, 70, 133, 62, 95, 157, 227, 64, 8, 167, 146, 189, 18, 233, 218, 64, 10, 82, 71, 190, 149, 223, 151, 62, 159, 92, 231, 64, 134, 46, 65, 62, 5, 229, 215, 64, 40, 183, 213, 64, 128, 119, 90, 190, 61, 50, 231, 64, 79, 234, 176, 62, 69, 51, 230, 64, 0, 36, 1, 62, 204, 241, 147, 62, 168, 136, 85, 190, 160, 180, 82, 190, 186, 133, 159, 190, 26, 52, 121, 190, 235, 185, 142, 62, 24, 130, 241, 61, 248, 209, 71, 189, 96, 29, 81, 190, 109, 175, 144, 62, 122, 150, 167, 190, 229, 189, 136, 62, 126, 105, 123, 62, 159, 3, 91, 190, 176, 61, 157, 189, 124, 246, 151, 190, 44, 19, 254, 189, 222, 46, 58, 62, 210, 171, 17, 62, 48, 174, 51, 189, 175, 61, 55, 190, 120, 42, 58, 189, 129, 92, 73, 190, 51, 199, 178, 190, 58, 201, 97, 62, 177, 255, 10, 190, 182, 12, 35, 190, 150, 219, 9, 62, 128, 127, 24, 187, 108, 205, 150, 61, 148, 35, 155, 190, 144, 6, 203, 61, 79, 24, 139, 62, 186, 133, 76, 62, 48, 50, 214, 64, 6, 210, 38, 62, 96, 150, 224, 64, 8, 27, 35, 190, 114, 181, 14, 62, 245, 179, 220, 64, 200, 10, 102, 61, 50, 94, 226, 64, 55, 124, 213, 64, 74, 6, 14, 190, 124, 251, 214, 64, 181, 164, 26, 190, 13, 124, 231, 64, 240, 56, 177, 189, 42, 137, 40, 62, 0, 0, 6, 0, 8, 0, 4, 0, 6, 0, 0, 0, 4, 0, 0, 0, 128, 0, 0, 0, 39, 172, 179, 64, 151, 247, 178, 64, 0, 0, 0, 0, 103, 37, 180, 64, 62, 148, 117, 188, 235, 212, 179, 64, 0, 0, 0, 0, 10, 184, 179, 64, 79, 38, 180, 64, 97, 5, 180, 64, 43, 200, 179, 64, 32, 151, 243, 188, 0, 0, 0, 0, 132, 167, 179, 64, 0, 0, 0, 0, 0, 0, 0, 0, 53, 185, 179, 64, 211, 136, 42, 188, 47, 31, 174, 64, 140, 222, 179, 64, 0, 0, 0, 0, 140, 159, 167, 187, 0, 0, 0, 0, 90, 11, 135, 187, 161, 207, 179, 64, 0, 0, 0, 0, 19, 145, 178, 64, 47, 201, 196, 187, 129, 197, 179, 64, 0, 0, 0, 0, 0, 0, 0, 0, 238, 4, 180, 64, 220, 253, 255, 255, 224, 253, 255, 255, 15, 0, 0, 0, 77, 76, 73, 82, 32, 67, 111, 110, 118, 101, 114, 116, 101, 100, 46, 0, 1, 0, 0, 0, 20, 0, 0, 0, 0, 0, 14, 0, 24, 0, 20, 0, 16, 0, 12, 0, 8, 0, 4, 0, 14, 0, 0, 0, 20, 0, 0, 0, 28, 0, 0, 0, 108, 0, 0, 0, 112, 0, 0, 0, 116, 0, 0, 0, 4, 0, 0, 0, 109, 97, 105, 110, 0, 0, 0, 0, 1, 0, 0, 0, 20, 0, 0, 0, 0, 0, 14, 0, 22, 0, 0, 0, 16, 0, 12, 0, 11, 0, 4, 0, 14, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 8, 24, 0, 0, 0, 28, 0, 0, 0, 0, 0, 6, 0, 8, 0, 7, 0, 6, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 60, 1, 0, 0, 200, 0, 0, 0, 96, 0, 0, 0, 4, 0, 0, 0, 234, 254, 255, 255, 0, 0, 0, 1, 20, 0, 0, 0, 28, 0, 0, 0, 28, 0, 0, 0, 4, 0, 0, 0, 52, 0, 0, 0, 2, 0, 0, 0, 255, 255, 255, 255, 32, 0, 0, 0, 212, 254, 255, 255, 25, 0, 0, 0, 83, 116, 97, 116, 101, 102, 117, 108, 80, 97, 114, 116, 105, 116, 105, 111, 110, 101, 100, 67, 97, 108, 108, 58, 48, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 32, 0, 0, 0, 178, 255, 255, 255, 0, 0, 0, 1, 16, 0, 0, 0, 16, 0, 0, 0, 3, 0, 0, 0, 44, 0, 0, 0, 28, 255, 255, 255, 31, 0, 0, 0, 115, 101, 113, 117, 101, 110, 116, 105, 97, 108, 95, 49, 56, 47, 110, 110, 95, 108, 97, 121, 101, 114, 95, 53, 47, 77, 97, 116, 77, 117, 108, 0, 2, 0, 0, 0, 32, 0, 0, 0, 16, 0, 0, 0, 0, 0, 22, 0, 24, 0, 20, 0, 0, 0, 16, 0, 12, 0, 8, 0, 0, 0, 0, 0, 0, 0, 7, 0, 22, 0, 0, 0, 0, 0, 0, 1, 16, 0, 0, 0, 16, 0, 0, 0, 2, 0, 0, 0, 60, 0, 0, 0, 128, 255, 255, 255, 47, 0, 0, 0, 115, 101, 113, 117, 101, 110, 116, 105, 97, 108, 95, 49, 56, 47, 110, 110, 95, 108, 97, 121, 101, 114, 95, 53, 47, 66, 105, 97, 115, 65, 100, 100, 47, 82, 101, 97, 100, 86, 97, 114, 105, 97, 98, 108, 101, 79, 112, 0, 1, 0, 0, 0, 32, 0, 0, 0, 0, 0, 22, 0, 28, 0, 24, 0, 0, 0, 20, 0, 16, 0, 12, 0, 0, 0, 0, 0, 8, 0, 7, 0, 22, 0, 0, 0, 0, 0, 0, 1, 20, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 1, 0, 0, 0, 64, 0, 0, 0, 2, 0, 0, 0, 255, 255, 255, 255, 16, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 34, 0, 0, 0, 115, 101, 114, 118, 105, 110, 103, 95, 100, 101, 102, 97, 117, 108, 116, 95, 110, 110, 95, 108, 97, 121, 101, 114, 95, 53, 95, 105, 110, 112, 117, 116, 58, 48, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 1, 0, 0, 0, 16, 0, 0, 0, 12, 0, 12, 0, 11, 0, 0, 0, 0, 0, 4, 0, 12, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 9
};

# -*- coding: utf-8 -*-
"""
Created on Sat Aug 18 14:18:24 2018

@author: Neil
"""

import cv2
import sys
#主函数
if __name__ == "__main__":
    if len(sys.argv) > 1:
        #输入图像
        src = cv2.imread(sys.argv[1], cv2.IMREAD_ANYCOLOR)
    else:
        print("Usge:python normlize.py imageFile")
    #直方图正规化
    dst = src
    cv2.normalize(src, dst, 255, 0, cv2.NORM_MINMAX, cv2.CV_8U)
    #显示原图和直方图正规化的效果
    cv2.imshow("src", src)
    cv2.imshow("dst", dst)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
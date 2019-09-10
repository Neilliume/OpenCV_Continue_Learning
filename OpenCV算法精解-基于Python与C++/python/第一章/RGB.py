# -*- coding: utf-8 -*-
"""
Created on Mon Aug 13 23:24:34 2018

@author: Neil
"""

import cv2
import numpy as np
import sys
#主函数
if __name__ == "__main__":
    if len(sys.argv) > 1:
        image = cv2.imread(sys.argv[1], cv2.IMREAD_COLOR)
    else:
        print("Usge:python RGB.py imageFile")
    #得到三个颜色通道
    b = image[:, :, 0]
    g = image[:, :, 1]
    r = image[:, :, 2]
    #显示三个颜色通道
    cv2.imshow("b", b)
    cv2.imshow("g", g)
    cv2.imshow("r", r)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
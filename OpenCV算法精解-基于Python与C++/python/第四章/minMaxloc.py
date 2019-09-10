# -*- coding: utf-8 -*-
"""
Created on Sat Aug 18 14:03:12 2018

@author: Neil
"""

import cv2
import numpy as np
import sys
#主函数
if __name__ == "__main__":
    #读入图像
    image = cv2.imread(sys.argv[1], cv2.IMREAD_GRAYSCALE)
    #求I的最大值、最小值
    Imax = np.max(image)
    Imin = np.min(image)
    #要输出的最小灰度级和最大灰度级
    Omin,Omax = 0,255
    #计算a和b的值
    a = float(Omax - Omin) / (Imax - Imin)
    b = Omin - a * Imin
    #矩阵的线性变换
    O = a * image + b
    #数据类型转换
    O = O.astype(np.uint8)
    #显示原图和直方图正规化的效果
    cv2.imshow("src", image)
    cv2.imshow("output", O)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
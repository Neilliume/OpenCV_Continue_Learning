# -*- coding: utf-8 -*-
"""
Created on Sun Aug 19 10:52:27 2018

@author: Neil
"""

import cv2
import numpy as np
import sys
#主函数
if __name__ == "__main__":
    #读入图像
    I = cv2.imread(sys.argv[1], cv2.IMREAD_GRAYSCALE)
    #图像归一化
    fI = I / 255.0
    #伽马变换
    gamma = 2
    O = np.power(fI, gamma)
    #显示原图和伽马变换后的效果
    cv2.imshow("I", I)
    cv2.imshow("O", O)
    cv2.waitKey()
    cv2.destroyAllWindows()
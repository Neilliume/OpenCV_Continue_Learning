# -*- coding: utf-8 -*-
"""
Created on Sun Aug 12 23:45:03 2018

@author: Neil
"""

import sys
import cv2
import numpy as np
#主函数
if __name__ == "__main__":
    #输入图像矩阵，转换为array
    #注意，运行方法是在目录文件夹下右键，打开powershell
    #然后输入 python xx.py xx.jpg
    #注意  输入的py和jpg文件路径中不要有中文名，否则无法显示
    if len(sys.argv) > 1:
        img = cv2.imread(sys.argv[1], cv2.IMREAD_GRAYSCALE)
    else:
        print("Usge:python imgToArray.py imageFile")
    #显示图像
    cv2.imshow("img", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
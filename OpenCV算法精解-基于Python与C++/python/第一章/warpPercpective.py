# -*- coding: utf-8 -*-
"""
Created on Tue Aug 14 23:29:55 2018

@author: Neil
"""

import numpy as np
import cv2
import sys
#主函数
if __name__ == "__main__":
    if len(sys.argv) > 1:
        image = cv2.imread(sys.argv[1], cv2.IMREAD_GRAYSCALE)
    else:
        print("Usage:python warpPercpective.py image")
    #原图的高、宽
    h,w = image.shape
    #原图的四个点与投影变换对应的点
    src = np.array([[0, 0], [w - 1, 0], [0, h - 1], [w - 1, h - 1]], np.float32)
    dst = np.array([[50, 50], [w / 3, 50], [50, h - 1], [w - 1, h - 1]], np.float32)
    #计算投影变换矩阵
    p = cv2.getPerspectiveTransform(src, dst)
    #利用计算出的投影变换矩阵进行头像的投影变换
    r = cv2.warpPerspective(image, p, (w, h), borderValue = 125)
    #显示原图和投影效果
    cv2.imshow("image", image)
    cv2.imshow("warpPerspective", r)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
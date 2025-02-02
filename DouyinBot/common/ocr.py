#-*- coding: UTF-8 -*-
#图片分析类

import cv2

import os 


def ocr():
	
	img=cv2.imread("../autojump.png",0)
	h,w=img.shape

	img=img[h//2:h-350,0:w]



	_,img=cv2.threshold(img,177,255,cv2.THRESH_BINARY)


	#img=cv2.morphologyEx(img,cv2.MORPH_OPEN,(5,5))
	#img=cv2.GaussianBlur(img,(5,5),0)
	cv2.imwrite('../autojump_t.jpg',img)
	#cv2.imshow("image", img) # 显示图片，
	#cv2.waitKey(0) #等待按键
	
	
	os.system(' tesseract  ../autojump_t.jpg ../out  -l eng+chi_sim')
	
	
def p_to_t():
	name = []
	data = []
	#people = []
	#share =[]
	with open ('../out.txt', 'r') as f:
		line=f.readlines()
		data1=line [1:]
		for i in data1:
			if i =='\n':
				data1.remove('\n')
		data1=''.join(map(str,data1))
		
		data2=sub_c(data1[:-8])
		data.append(data2+data1[-8:])
		
		name.append(sub_c(line[0]))

		print('完成图片识别\n','言语：\n',data[0],'\n账号名：\n',name[0])
		
		
		
		
		
		
		run_n=1
		
		return run_n,data,name
		
		
def sub_c(line):
		n1=line.replace('\n','')
		n2=n1.replace(' ','')
		return n2


def main():
	ocr()
	n,name,date=p_to_t()
	f1=open('../out_name.txt','a')
	f2=open('../out_date.txt','a')
	if n == 1:
		#f1.read ()
		f1.write('\n'+name[0]+'\n')
		f1.close()
		#f2.read ()
		f2.write ('\n' + date[0] + '\n')
		f2.close()
	else:
		print('写入文件失败')
	#os.remove ('../autojump_t.jpg')
	#os.remove ('../out.txt')
	

	
main()
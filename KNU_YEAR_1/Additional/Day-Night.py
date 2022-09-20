from tkinter import *
from math import *
import random
import math
root = Tk()
root.title("Day & Night")

WIDTH = 800
HEIGHT = 600        

cn = Canvas(root, width = WIDTH, height = HEIGHT, bg = "LightSkyBlue1")

cn.pack()

################################################################################################################################################
def set_day (d_n) :

    def set_background () :
        cn.create_rectangle(0,0, 800,600,fill = "LightSkyBlue1", outline = "LightSkyBlue1", width = 0)
        cn.create_rectangle(0, 300, 802, 602, fill = "green", outline = "green", width = 0)

    def sun (x0, y0, R) :
        
        cn.create_oval(x0-R/sqrt(2),y0+R/sqrt(2), x0+R/sqrt(2), y0-R/sqrt(2), fill = "yellow" ,outline = "yellow1", width = 1)
        for i in range (0, 150):
            y1=random.randint(0,160)
            if (y1<40) or 130>y1>80:
                x1=random.randint(140,290)
            elif 40<y1<130:
                x1=random.randint(110,320)
            else:
                x1=random.randint(150,280)
            cn.create_line(x0, y0, x1, y1, fill = "yellow", width=2)
    
    
    def build_the_house () :

        cn.create_rectangle(450,480,750,230, fill = "burlywood1", outline = "orange2", width = 1) 

        cn.create_rectangle(630,150, 660,105, fill = "grey67",outline = "grey45",width = 1) 

        cn.create_rectangle(625,105, 665,95, fill = "grey67",outline = "grey45",width = 1) 

        cn.create_polygon(410,230, 600,100, 790,230 ,fill = "sandy brown",outline = "burlywood4",width = 1) 

        cn.create_rectangle(470,480, 560,330,fill = "sandy brown", outline = "burlywood4", width = 1) 

        cn.create_rectangle(600,420, 690,330,fill = "sandy brown", outline = "burlywood4", width = 1) 

        cn.create_rectangle(605,415, 685,335,fill = "SteelBlue1", outline = "burlywood4", width = 1)

        cn.create_oval(480,420, 490,410, fill = "gold" ,outline = "orange2", width = 1) 
    


    def fence (x0, y0, n) :
        while n > 0 :
              
            if(n != 1) :
                
                cn.create_rectangle(x0, y0, x0+20, y0-70, fill = "tan2" ,outline = "tan3", width = 1)
                cn.create_polygon(x0,y0-70, x0+10, y0-80, x0+20, y0-70, fill = "tan2" ,outline = "tan3", width = 1)

                cn.create_rectangle(x0+20, y0-30, x0+30, y0-20, fill = "tan2" ,outline = "tan3", width = 1)
                cn.create_rectangle(x0+20, y0-55, x0+30, y0-45, fill = "tan2" ,outline = "tan3", width = 1)

                x0 = x0 + 30
                
            else :
                cn.create_rectangle(x0, y0, x0+20, y0-70, fill = "tan2" ,outline = "tan3", width = 1)
                cn.create_polygon(x0,y0-70, x0+10, y0-80, x0+20, y0-70, fill = "tan2" ,outline = "tan3", width = 1)

            n = n - 1  

    def spruce(x0, y0, n) :
        cn.create_rectangle(x0, y0, x0+24.0, y0-60.0, fill = "tan4" ,outline = "saddle brown", width = 1)
        x0 = x0 + 12.0
        y0 = y0 - 60.0
        k = 1
        while n > 0 :
            cn.create_polygon(x0-k*65.0,y0, x0, y0-k*70,  x0+k*65.0, y0, fill = "lime green" ,outline = "forest green", width = 1)
            k*=0.8
            y0 = y0-k*65
            n = n - 1

    

    def cloud (x0, y0) :
    
        cn.create_oval(x0,y0, x0+60, y0-60, fill = "white" ,outline = "white", width = 1)
        x0+=37
        cn.create_oval(x0-10,y0+10, x0+70, y0-70, fill = "white" ,outline = "white", width = 1)
        x0+=37
        cn.create_oval(x0,y0, x0+60, y0-60, fill = "white" ,outline = "white", width = 1)
 
    

    set_background()
    
    build_the_house()

    cloud (400, 90)
    
    fence(350, 570, 14)

    spruce(100.0,380.0, 5)
        
    sun(215, 60, 74)

    
################################################################################################################################################

def set_night (n_n) :

    def set_background () :
        cn.create_rectangle(0,0, 802,602,fill = "DeepSkyBlue4", outline = "DeepSkyBlue4", width = 0)
        cn.create_rectangle(0, 300, 802, 602, fill = "green", outline = "green", width = 0)

    def stars():
        for i in range(0, 25):
            x1=random.randint(0,800)
            y1=random.randint(0,220)
            cn.create_text(x1, y1, text="*",font="12", fill="white")


    def build_the_house () :

        cn.create_rectangle(450,480,750,230, fill = "burlywood3", outline = "orange4", width = 1) 

        cn.create_rectangle(630,150, 660,105, fill = "grey55",outline = "grey34",width = 1) 

        cn.create_rectangle(625,105, 665,95, fill = "grey55",outline = "grey34",width = 1)

        cn.create_polygon(410,230, 600,100, 790,230 ,fill = "tan3",outline = "burlywood4",width = 1)

        cn.create_rectangle(470,480, 560,330,fill = "tan3", outline = "burlywood4", width = 1) 

        cn.create_rectangle(600,420, 690,330,fill = "tan3", outline = "burlywood4", width = 1) 

        cn.create_rectangle(605,415, 685,335,fill = "SteelBlue3", outline = "burlywood4", width = 1) 

        cn.create_oval(480,420, 490,410, fill = "gold2" ,outline = "orange3", width = 1) 

    def spruce(x0, y0, n) :
        cn.create_rectangle(x0, y0, x0+24.0, y0-60.0, fill = "tan4" ,outline = "saddle brown", width = 1)
        x0 = x0 + 12.0
        y0 = y0 - 60.0
        k = 1
        while n > 0 :
            cn.create_polygon(x0-k*65.0,y0, x0, y0-k*70,  x0+k*65.0, y0, fill = "forest green" ,outline = "dark green", width = 1)
            k*=0.8
            y0 = y0-k*65
            n = n - 1

    def fence (x0, y0, n) :
        while n > 0 :
              
            if(n != 1) :
                
                cn.create_rectangle(x0, y0, x0+20, y0-70, fill = "tan3" ,outline = "tan4", width = 1)
                cn.create_polygon(x0,y0-70, x0+10, y0-80, x0+20, y0-70, fill = "tan3" ,outline = "tan4", width = 1)

                cn.create_rectangle(x0+20, y0-30, x0+30, y0-20, fill = "tan3" ,outline = "tan4", width = 1)
                cn.create_rectangle(x0+20, y0-55, x0+30, y0-45, fill = "tan3" ,outline = "tan4", width = 1)

                x0 = x0 + 30
                
            else :
                cn.create_rectangle(x0, y0, x0+20, y0-70, fill = "tan3" ,outline = "tan4", width = 1)
                cn.create_polygon(x0,y0-70, x0+10, y0-80, x0+20, y0-70, fill = "tan3" ,outline = "tan4", width = 1)

            n = n - 1 


    def moon (x0, y0, R) :
        cn.create_oval(x0-R/sqrt(2),y0+R/sqrt(2), x0+R/sqrt(2), y0-R/sqrt(2), fill = "azure2" ,outline = "azure2", width = 3)
        x0+=15
        y0+=5
        cn.create_oval(x0-R/sqrt(2),y0+R/sqrt(2), x0+R/sqrt(2), y0-R/sqrt(2), fill = "DeepSkyBlue4" ,outline = "DeepSkyBlue4", width = 0)
   

    set_background()

    stars()

    build_the_house()

    fence(350, 570, 14)
    
    spruce(100.0,380.0, 5)

    moon(260, 70, 70)
        
################################################################################################################################################

def main () :

    set_day(" ")
    
    butday = Button(root, width = 12, height = 2)
    butnight = Button(root, width = 12, height = 2)

    butday ["text"] = "Day"
    butnight ["text"] = "Night"

    butday.bind("<Button-1>", set_day)
    butnight.bind("<Button-1>", set_night)

    butday.pack()
    butnight.pack()

    root.mainloop()
    
################################################################################################################################################

main()


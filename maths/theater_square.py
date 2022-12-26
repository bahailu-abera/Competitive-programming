def calculate(width, height, sqr_side):
    w = width // sqr_side
    h = height // sqr_side
    
    if w * sqr_side != width:
        w += 1
    
    if h * sqr_side != height:
        h += 1
        
    print("{}".format(h * w))
    

if __name__ == "__main__":
    width, height, side = input().split()
    calculate(int(width), int(height), int(side))

import os
import re

# ls
# print(os.listdir("/"))

# execute command, and return the output  
def execCmd(cmd):  
    r = os.popen(cmd)  
    text = r.read()  
    r.close()  
    return text  

# write "data" to file-filename  
def writeFile(filename, data):  
    f = open(filename, "w")  
    f.write(data)  
    f.close()  

# 获取计算机MAC地址和IP地址  
if __name__ == '__main__':  
    cmd = "ls"  
    result = os.system(cmd)
    print(result)
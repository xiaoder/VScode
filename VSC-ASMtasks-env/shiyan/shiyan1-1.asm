data segment
	var1 dw 35, 24, 0451h	;定义源操作数
	var2 dw 3 dup(?)     	;定义目的操作数
data    ends
code segment
	      assume ds:data, cs:code
	start:mov    ax, data        	;数据段初始化
	      mov    ds, ax
	      lea    si, var1
	      lea    di, var2
	      mov    ax, [si]        	;传送第一个数
	      mov    [di], ax
	      add    si, 2
	      mov    ax, [si]        	;传送第二个数
	      mov    [di], ax
	      add    si, 2
	      add    di, 2
	      mov    ax, [si]        	;传送第三个数
	      mov    [di], ax
	      mov    ah, 4ch         	;程序返回
	      int    21h
code    ends
        end start
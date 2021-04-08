data segment
	str1 db 'ABCDEF'
	str2 db 6 dup(?)	;给str2预留存储单元
data    ends
code segment
	      assume ds:data, cs:code
	start:mov    ax,data         	;数据段初始化
	      mov    ds, ax
	      mov    cx, 6           	;循环次数送cx中
	      lea    si, str1
	      lea    di, str2
	rest: mov    al, [si]        	;传送一个字符
	      mov    [di], al
	      inc    si              	;修改si，di数值
	      inc    di
	      dec    cx              	;修改循环次数
	      jnz    rest            	;若cx!=0转到rest
	      mov    ah, 4ch         	;程序返回
	      int    21h
code    ends
        end start
# ROP-Temp
The Owner of this repo is not liable to any __Mal Use/Mal Practice__ doNE by the code written.

_I am going to assume you already know what you're doing with this chain but heres a breif explaintion of what it  is and how it works._


``ROP (Return-Oriented Programming) is a method of exploiting a computer program that allows an attacker to execute arbitrary code in the program by arranging existing code snippets from the program in a new order. These code snippets, called "gadgets," end with a return instruction, hence the name "Return-Oriented Programming."

To perform a ROP attack, the attacker must first find a way to control the flow of the program, such as by overflowing a buffer to overwrite a return address on the stack. The attacker can then insert pointers to gadgets into the controlled flow, causing the program to execute the gadgets in a desired order.

To chain these gadgets together, the attacker arranges the gadgets so that the final gadget in the chain returns to a controlled location in the program, such as the attacker's injected code. This allows the attacker to execute a sequence of gadgets that achieve a desired goal, such as bypassing security checks or escalating privileges.``

	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func

	.global fibonacci
	.type fibonacci, function

fibonacci:
	@ ADD/MODIFY CODE BELOW
	@ PROLOG
	@ prologue 開場
	@ PROLOG 
	@ epilogue 串場
	push {r3, r4, r5, lr}
@ This is the non-Recursive version.
@ enters a for loop, where r4 is the index from input
@ the subroutine ends when i==0 or 1,with return value 1
@ or fulfilled the loop condition

@ R0  (update flags)
@ r0 for storing index value 
@ ends the subroutine if i<=2, i>46 out of range of int
cmp r0, #2;
ble .L5; 

cmp r0, #46;
bgt .L6;

@ init the tmp data
@ r3 for N-1
mov r3, #1;
@ r4 for N-2
mov r4, #1;


.loop:
@ if(n>=2;n--)
@ 	F(n) = F(n-1) + F(n-2)

add r5, r3, r4;

@store r3, r4 for next time
mov r4, r3;
mov r3, r5;

sub r0, #1;
cmp r0, #2;
bgt .loop;

@ return point of n>2
mov r0, r5;
pop {r3, r4, r5, pc}	@EPILOG
@end of code MODIFICATION


.L5:	@end of sub routine (n<=2)
	mov r0, #1;
	pop {r3, r4, r5, pc}	@EPILOG
.L6: @ end of subroutine (n>46)
	mov r0, #0;
	pop {r3, r4, r5, pc}	@EPILOG

	@ END CODE MODIFICATION
	.size fibonacci, .-fibonacci
	.end

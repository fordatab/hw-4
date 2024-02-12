// CES30 assignment template
// 
// cse30sp23id: 
//
// Describe target Hardware to the assembler
.arch   armv6
.cpu    cortex-a53
.syntax unified
/////////////////////////////////////////////////////////

.text                       // start of the text segment
/////////////////////////////////////////////////////////
// function hashFun 
/////////////////////////////////////////////////////////
.type   hashFun, %function  // define as a function
.global hashFun             // export function name
.equ    FP_OFFSET, 28       // (regs - 1) * 4
/////////////////////////////////////////////////////////

// put any .equ for hashFun here - delete this line

/////////////////////////////////////////////////////////

hashFun:
    push    {r4-r9, fp, lr}     // use r4-r9 protected regs
    add     fp, sp, FP_OFFSET   // locate our frame pointer
    // DO NOT EDIT PROLOGUE ABOVE
    // You can use temporary r0-r3 and preserved r4-r9
    // Store return value (results) in r0
    ///////////////////////////////////////////////////////
    
    lsl r2, r1, 6               // Store the left shifted bits to r2
    lsl r3, r1, 16              // Store the left shifted bits to r3
    sub r1, r0, r1              // Sub c by hash and store in r1
    add r1, r1, r2              // Add r2 to r1
    add r1, r1, r3              // Add r3 to r1
    mov r0, r1                  // Move result to r0
    
    ///////////////////////////////////////////////////////
    // DO NOT EDIT EPILOGUE BELOW
    sub     sp, fp, FP_OFFSET   // restore sp
    pop     {r4-r9, fp, lr}     // restore saved registers
    bx      lr                  // function return
    .size   hashFun,(.-hashFun)

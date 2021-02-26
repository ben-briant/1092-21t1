
main:
    
    li $s0, 0                   #sum = 0
    li $s1, 0                   #r = 0   
    li $s2, 0                   #c = 0 - redundant 
    lw $s4, nrows   
    lw $s5, ncols

while_row:
    bge $s1, $s4, end_while_row #if r >= nrows goto end_while_row
    li $s2, 0                   #c = 0;
while_col:
    bge $s2, $s5, end_while_col #if c >= ncols goto end_while_col   
 
    # TODO: Load a[r][c] into $t0
    la $t1, a
    # Calculate the row offset
    mul $t2, $s5, 4         # Size of each row
    mul $t2, $t2, $s1       # Row offset in $t2

    mul $t3, $s2, 4         # Col offset in $t3

    add $t1, $t1, $t2
    add $t1, $t1, $t3

    # Now, $t1 contains &a[r][c]
    lw $t0, ($t1)

    add $s0, $s0, $t0           #sum = sum + a[r][c]
 
    addi $s2, $s2, 1            #c++  
    j while_col  
end_while_col:
    addi $s1, $s1, 1            #r++
    j while_row
end_while_row:

    li $v0, 1                   #printf("%d",sum);
    move $a0, $s0
    syscall
    
    li $v0, 11                  #printf("%c",'\n');
    li $a0, '\n'
    syscall
    
    li $v0, 0                   #return 0
    jr $ra


    .data
nrows: .word 3
ncols: .word 5
a:  .word 2, 4, 1, 5, 8
    .word 9, 1, 0, 2, 3
    .word 1, 1, 4, 6, 3

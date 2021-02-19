
main:
    la $s0, str     # s in $s0

    li $v0, 12
    syscall
    move $s1, $v0   # c in $s1

start_while:
    # Get *s
    lb $t0, ($s0) # *s in $t0
    beq $t0, 0, end_while

    bne $t0, $s1, end_if
    
    li $v0, 4
    la $a0, found
    syscall

    li $v0, 11
    move $a0, $s1
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall
    
    j end_while

end_if:
    addi $s0, $s0, 1
    j start_while

end_while:
    li $v0, 0
    jr $ra

    .data
str:
    .asciiz "Hello"
found:
    .asciiz "Found "

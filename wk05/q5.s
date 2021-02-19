
main:
    # TODO: Complete
    li $v0, 12
    syscall
    move $s0, $v0       # c in $s0

    la $s1, str         # s in $s1

start_while:
    lb $t0, ($s1)       # *s in $t0
    beq $t0, 0, end_while
    bne $t0, $s0, end_if

    li $v0, 4
    la $a0, found_msg
    syscall

    li $v0, 11
    move $a0, $s0
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    j end_while

end_if:
    addi $s1, $s1, 1
    j start_while

end_while:
    jr $ra


    .data
str:
    .asciiz "Hello"
found_msg:
    .asciiz "Found "
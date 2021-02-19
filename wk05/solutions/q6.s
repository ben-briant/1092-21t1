main:
    lw $s0, len     # len in $s0
    lw $s1, a       # max in $s1
    la $s2, a       # a in $s2

    li $t0, 1       # i in $t0

start_while:
    bge $t0, $s0, end_while
    # Calculate a[i]
    mul $t1, $t0, 4     # offset in $t1
    add $t2, $t1, $s2   # &a[i] in $t2
    lw $t3, ($t2)       # a[i] in $t3

    ble $t3, $s1, end_if

    move $s1, $t3

end_if:
    addi $t0, $t0, 1
    j start_while

end_while:
    li $v0, 4
    la $a0, max_str
    syscall

    li $v0, 1
    move $a0, $s1
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    li $v0, 0
    jr $ra

    .data
a:
    .word 4, 3, 4, 1, 9, 7
len:
    .word 6
max_str:
    .asciiz "Max is "

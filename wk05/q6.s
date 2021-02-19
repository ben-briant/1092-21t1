
main:
    # TODO: Complete
    lw $s0, a       # max in $s0
    lw $s1, len     # len in $s1

    li $t0, 1       # i in $t0

start_while:
    bge $t0, $s1, end_while

    mul $t1, $t0, 4 # Offset into the array
    la $t2, a       # address of a in $t2
    add $t3, $t1, $t2 # &a[i] in $t3

    lw $s2, ($t3)   # a[i] in $s2

    ble $s2, $s0, end_if

    move $s0, $s2

end_if:
    addi $t0, $t0, 1

    j start_while

end_while:
    li $v0, 4
    la $a0, max_str
    syscall

    li $v0, 1
    move $a0, $s0
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    jr $ra


    .data
a:
    .word 4, 3, 52, 1, 9, 7
len:
    .word 6

max_str:
    .asciiz "Max is "
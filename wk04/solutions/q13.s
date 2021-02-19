main:
    li $v0, 5
    syscall
    move $s0, $v0   # n in $s0

    li $t0, 0       # i in $t0

loop1:
    bge $t0, $s0, end1
    li $t1, 0       # j in $t1

loop2:
    bge $t1, $s0, end2

    li $a0, '*'
    li $v0, 11
    syscall

    addi $t1, $t1, 1
    j loop2

end2:
    li $a0, '\n'
    li $v0, 11
    syscall

    addi $t0, $t0, 1
    j loop1

end1:
    jr $ra
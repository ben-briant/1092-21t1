
# TODO: Complete this program
main:
    li $v0, 5 # Perform the "read int" syscall
    syscall
    move $s0, $v0   # n in $s0

    li $v0, 1
    move $a0, $s0
    syscall

    rem $t0, $s0, 2
    beqz $t0, even

    li $v0, 4
    la $a0, is_odd
    syscall

    j end_if

even:
    li $v0, 4
    la $a0, is_even
    syscall

end_if:
    jr $ra

    .data
is_even:
    .asciiz " is even\n"
is_odd:
    .asciiz " is odd\n"
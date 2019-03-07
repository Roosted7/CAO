		.text
		j	main						# Jump to main-routine

		.data
str1:	.asciiz "Insert the array size \n"
str2:	.asciiz "Insert the array elements,one per line  \n"
str3:	.asciiz "The sorted array is : \n"
str5:	.asciiz "\n"

		.text
		.globl	main

# Action: swap elements v[i] and v[j]
# void swap (int v[], int i, int j)	

# $a0 = base address af the array
# $a1 = i
# $a2 = j
swap:
		sll	$t0, $a1, 2					# $t0 = i*4
		add	$t1, $t0, $a0				# $t1 = $a0+i*4 (adr of i)

		sll	$t0, $a2, 2					# $t0 = j*4
		add	$t2, $t0, $a0				# $t1 = $a0+j*4 (adr of j)

		lw $t3, 0($t1)					# $t3 (tmp) = v[i]
		lw $t4, 0($t2)					# $t4 = v[j]
		sw $t4, 0($t1)
		sw $t3, 0($t2)

		jr $ra


# Result: index of the smallest element in the array
# v[first], v[first+1], ... , v[last]
# $a0 = base address af the array
# $a1 = first
# $a2 = last

# $s0 = min
# $s1 = i

# $v0 = mini
imin:
		addi $sp, $sp, -12			# save values on stack
		sw	$ra, 0($sp)
		sw	$s0, 4($sp)
		sw	$s1, 8($sp)

		# mini = first;
		move	$v0, $a1				# $v0 = $a2

		# min = v[first];
		sll	$t0, $a1, 2					# $t0 = i*4
		add	$t1, $t0, $a0				# $t1 = $a0+first*4 (adr of first)
		lw $s0, 0($t1)

		# i = first + 1
		addi $s1, $a1, 1

for_imin:								# for loop
		# If i > last, then done
		bgt $s1, $a2, exit_imin

		# $t2 = v[i];
		sll	$t0, $s1, 2					# $t0 = i*4
		add	$t1, $t0, $a0				# $t1 = $a0+first*4 (adr of v[i])
		lw $t2, 0($t1)

		# if v[i] >= min, skip if
		bge $t2, $s0, end_if_imin

		move $v0, $s1					# mini = i
		move $s0, $t2					# min = v[i]

end_if_imin:
		# End of for
		addi $s1, $s1, 1			# i++
		j for_imin					#

exit_imin:
		lw	$ra, 0($sp)		# restore values from stack
		lw	$s0, 4($sp)
		lw	$s1, 8($sp)
		addi $sp, $sp, 12		# restore stack pointer
		jr $ra
		
# Action: sort table a[]
# $a0 = base address af the array
# $a1 = size of the array

# $s0 = i
ssort:
	addi $sp, $sp, -12			# save values on stack
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)

	move 	$s0, $zero					# $s0 = 0
	addi	$s1, $a1, -1				# $t9 = $a1 - 1
for_ssort:
	# If i >= (length - 1), done and return to main
	bge $s0, $s1, exit_ssort

	move $a1, $s0
	move $a2, $s1
	jal imin								# jump to imin

	move $a2, $v0
	jal swap

	addi	$s0, $s0, 1			# $s0 = $s0 + 1
	j for_ssort
exit_ssort:
	lw	$ra, 0($sp)		# restore values from stack
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	addi $sp, $sp, 12		# restore stack pointer
	jr	$ra			# return

	
main: 
			la	$a0, str1					# Print of str1
			li	$v0, 4						#
			syscall							#

			li	$v0, 5						# Get the array size(n) and
			syscall							# and put it in $v0
			move	$s2, $v0				# $s2=n
			sll	$s0, $v0, 2					# $s0=n*4
			sub	$sp, $sp, $s0				# This instruction creates a stack
											# frame large enough to contain
											# the array
			la	$a0, str2					#
			li	$v0, 4						# Print of str2
			syscall							#
				
			move	$s1, $zero				# i=0
for_get:	bge	$s1, $s2, exit_get			# if i>=n go to exit_for_get
			sll	$t0, $s1, 2					# $t0=i*4
			add	$t1, $t0, $sp				# $t1=$sp+i*4
			li	$v0, 5						# Get one element of the array
			syscall							#
			sw	$v0, 0($t1)					# The element is stored
											# at the address $t1
			la	$a0, str5
			li	$v0, 4
			syscall
			addi	$s1, $s1, 1				# i=i+1
			j	for_get
exit_get:	move	$a0, $sp				# $a0=base address af the array
			move	$a1, $s2				# $a1=size of the array
			jal	ssort						# ssort(a,n)
											# In this moment the array has been 
											# sorted and is in the stack frame 
			la	$a0, str3					# Print of str3
			li	$v0, 4
			syscall

			move	$s1, $zero				# i=0
for_print:	bge	$s1, $s2, exit_print		# if i>=n go to exit_print
			sll	$t0, $s1, 2					# $t0=i*4
			add	$t1, $sp, $t0				# $t1=address of a[i]
			lw	$a0, 0($t1)					#
			li	$v0, 1						# print of the element a[i]
			syscall							#

			la	$a0, str5
			li	$v0, 4
			syscall
			addi	$s1, $s1, 1				# i=i+1
			j	for_print
exit_print:	add	$sp, $sp, $s0				# elimination of the stack frame 
              
			li	$v0, 10						# EXIT
			syscall							#

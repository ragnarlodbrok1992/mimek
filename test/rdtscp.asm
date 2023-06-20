; This is code for rdtsc since inline assembly is not supported in MSVC on x64 architecture
; use ml64 to compile and then link by hand

.CODE
PUBLIC __rdtscp_proc

; Input: None
; Output: rax - 64bit timestamp counter value and procid somewhere
__rdtscp_proc PROC
  rdtscp
  ret
__rdtscp_proc ENDP
END


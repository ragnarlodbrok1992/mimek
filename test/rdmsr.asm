; Code for rdmsr mnemonic

.CODE
PUBLIC __rdmsr_proc

; INPUT: rcx number
; OUTPUT: high 32 bits of MSR in rdx, low 32 bits of MSR in rax
__rdmsr_proc PROC
  ; rcx should be loaded at start with searched value
  rdmsr

  ; rdmsr returns - rdx - high 32 bits
  ; rax - low 32 bits
  ; mix them up in rcx, throw them to return value and ret
  
  mov ecx, edx
  shl rcx, 32
  or rcx, rax

  ; TEST ASM: how to return stuff
  mov rax, rcx
  ; mov qword prt [rsp + 8], rax
  
  ret

__rdmsr_proc ENDP
END

#include "cpu/exec.h"

make_EHelper(mov) {
  operand_write(id_dest, &id_src->val);
  print_asm_template2(mov);
}

make_EHelper(push) {
  // TODO();

  // printf("src1 = 0x%08x\tsrc2 = 0x%08x\tdest = 0x%08x\n", id_src->val, id_src2->val, id_dest->val);
  // printf("id_dest->val = %d | 0x%x\tid_dest->str = %s\n", id_dest->val, id_dest->val, id_dest->str);
  rtl_push(&id_dest->val, id_dest->width);

  print_asm_template1(push);
}

make_EHelper(pop) {
  // TODO();

  // printf("t2 = %d | 0x%x\n", t2, t2);
  rtl_pop(&t2);
  operand_write(id_dest, &t2);
  // printf("t2 = %d | 0x%x\n", t2, t2);

  print_asm_template1(pop);
}

make_EHelper(pusha) {
  TODO();

  print_asm("pusha");
}

make_EHelper(popa) {
  TODO();

  print_asm("popa");
}

make_EHelper(leave) {
  TODO();

  print_asm("leave");
}

make_EHelper(cltd) {
  if (decoding.is_operand_size_16) {
    TODO();
  }
  else {
    TODO();
  }

  print_asm(decoding.is_operand_size_16 ? "cwtl" : "cltd");
}

make_EHelper(cwtl) {
  if (decoding.is_operand_size_16) {
    TODO();
  }
  else {
    TODO();
  }

  print_asm(decoding.is_operand_size_16 ? "cbtw" : "cwtl");
}

make_EHelper(movsx) {
  id_dest->width = decoding.is_operand_size_16 ? 2 : 4;
  rtl_sext(&t2, &id_src->val, id_src->width);
  operand_write(id_dest, &t2);
  print_asm_template2(movsx);
}

make_EHelper(movzx) {
  id_dest->width = decoding.is_operand_size_16 ? 2 : 4;
  printf("src1->width = %d\tsrc2->width = %d\tdest->width = %d\n", id_src->width, id_src2->width, id_dest->width);
  printf("src1->str = %s\tsrc2->str = %s\tdest->str = %s\n", id_src->str, id_src2->str, id_dest->str);
  printf("src1 = 0x%08x\tsrc2 = 0x%08x\tdest = 0x%08x\n", id_src->val, id_src2->val, id_dest->val);

  operand_write(id_dest, &id_src->val);
  print_asm_template2(movzx);
}

make_EHelper(lea) {
  rtl_li(&t2, id_src->addr);
  operand_write(id_dest, &t2);
  print_asm_template2(lea);
}

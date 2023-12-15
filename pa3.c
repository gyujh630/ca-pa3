/**********************************************************************
 * Copyright (c) 2023
 *  Sang-Hoon Kim <sanghoonkim@ajou.ac.kr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include <stdio.h>

#include "types.h"

/***
 * External entities in other files.
 */
extern struct stage stages[];		/* Pipelining stages */

extern unsigned char memory[];		/* Memory */

extern unsigned int registers[];	/* Registers */

extern unsigned int pc;				/* Program counter */

/**
 * Helper functions that might be useful. See main.c for the details of them
 */
extern bool is_noop(int stage);
extern void make_stall(int stage, int cycles);


/**********************************************************************
 * List of instructions that should be supported
 *
 * | Name   | Format   | Opcode / opcode + funct |
 * | ------ | -------- | ----------------------- |
 * | `add`  | r-format | 0 + 0x20                |
 * | `addi` | i-format | 0x08                    |
 * | `sub`  | r-format | 0 + 0x22                |
 * | `and`  | r-format | 0 + 0x24                |
 * | `andi` | i-format | 0x0c                    |
 * | `or`   | r-format | 0 + 0x25                |
 * | `ori`  | i-format | 0x0d                    |
 * | `nor`  | r-format | 0 + 0x27                |
 * | `sll`  | r-format | 0 + 0x00                |
 * | `srl`  | r-format | 0 + 0x02                |
 * | `sra`  | r-format | 0 + 0x03                |
 * | `lw`   | i-format | 0x23                    |
 * | `sw`   | i-format | 0x2b                    |
 * | `slt`  | r-format | 0 + 0x2a                |
 * | `slti` | i-format | 0x0a                    |
 * | `beq`  | i-format | 0x04                    |
 * | `bne`  | i-format | 0x05                    |
 * | `jr`   | r-format | 0 + 0x08                |
 * | `j`    | j-format | 0x02                    |
 * | `jal`  | j-format | 0x03                    |
 */

void IF_stage(struct IF_ID *if_id)
{
	/***
	 * No need to check whether this stage is idle or not for some reasons...
	 */

	/* TODO: Read one instruction in machine code from the memory */
	unsigned int machine_code = 0xdeadbeef;

	/***
	 * Set @stages[IF].instruction.machine_code with the read machine code
	 * and @stages[IF].__pc with the current value of the program counter.
	 * DO NOT REMOVE THOSE TWO STATEMENTS, as they are required by the 
	 * framework to work correctly.
	 */
	stages[IF].instruction.machine_code = machine_code;
	stages[IF].__pc = pc;

	/* TODO: Fill in IF-ID interstage register */

	/***
	 * The framework processes @stage[IF].instruction.machine_code under
	 * the hood to allow you to access human-readable stages[*].instruction
	 * in the following stages. Check __run_cycle() in main.c.
	 */
}


void ID_stage(struct IF_ID *if_id, struct ID_EX *id_ex)
{
	struct instruction *instr = &stages[ID].instruction;

	if (is_noop(ID)) return;

	/***
	 * Register write should be taken place in WB_stage,
	 * so actually there is nothing to do here for register write.
	 */

	/* TODO: Process register read. May use if_id */

	/* TODO: Fill in ID-EX interstage register */
}

void EX_stage(struct ID_EX *id_ex, struct EX_MEM *ex_mem)
{
	struct instruction *instr = &stages[EX].instruction;

	if (is_noop(EX)) return;

	/* TODO: Good luck! */
}


void MEM_stage(struct EX_MEM *ex_mem, struct MEM_WB *mem_wb)
{
	struct instruction *instr = &stages[MEM].instruction;

	if (is_noop(MEM)) return;

	/* TODO: Happy coding */
}


void WB_stage(struct MEM_WB *mem_wb)
{
	struct instruction *instr = &stages[WB].instruction;

	if (is_noop(WB)) return;

	/* TODO: Fingers crossed */
}

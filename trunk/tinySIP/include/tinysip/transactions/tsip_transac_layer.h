/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_transac.h
 * @brief SIP transaction layer.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TINYSIP_TRANSAC_LAYER_H
#define TINYSIP_TRANSAC_LAYER_H

#include "tinysip_config.h"

#include "tsip.h"
#include "tinysip/transactions/tsip_transac.h"

#include "tsk_safeobj.h"
#include "tsk_list.h"

TSIP_BEGIN_DECLS

#define TSIP_TRANSAC_LAYER_CREATE(stack)			tsk_object_new(tsip_transac_layer_def_t, stack)
#define TSIP_TRANSAC_LAYER_SAFE_FREE(self)			tsk_object_unref(self), self = 0

typedef struct tsip_transac_layer_s
{
	TSK_DECLARE_OBJECT;

	const tsip_stack_handle_t *stack;

	tsip_transacs_L_t *transactions;

	TSK_DECLARE_SAFEOBJ;
}
tsip_transac_layer_t;

typedef tsk_list_t tsip_transac_layers_L_t;
TINYSIP_GEXTERN const void *tsip_transac_layer_def_t;


const tsip_transac_t* tsip_transac_layer_new(tsip_transac_layer_t *self, const tsip_message_t* msg);
int tsip_transac_layer_remove(tsip_transac_layer_t *self, const tsip_transac_t *transac);
const tsip_transac_t* tsip_transac_layer_find_client(const tsip_transac_layer_t *self, const char* branch, const char* cseq_method);

TSIP_END_DECLS

#endif /* TINYSIP_TRANSAC_LAYER_H */

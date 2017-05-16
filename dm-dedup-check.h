/*
 * Copyright (C) 2012-2014 Vasily Tarasov
 * Copyright (C) 2012-2014 Geoff Kuenning
 * Copyright (C) 2012-2014 Sonam Mandal
 * Copyright (C) 2012-2014 Karthikeyani Palanisami
 * Copyright (C) 2012-2014 Philip Shilane
 * Copyright (C) 2012-2014 Sagar Trehan
 * Copyright (C) 2012-2014 Erez Zadok
 *
 * This file is released under the GPL.
 */

#ifndef DM_DEDUP_CHECK_CORRUPTION_H
#define DM_DEDUP_CHECK_CORRUPTION_H

/*
 * check_io struct is used to pass arguments through 
 * struct bio, to be used later in the callback function
 */
struct check_io {
	struct dedup_config *dc;
	uint64_t pbn;
	uint64_t lbn;	
	struct bio *base_bio;
};

/*
 * check_work struct is used to initialize a dedicated
 * workqueue only for doing Forward error correction
 */
struct check_work {
        struct work_struct worker;
        struct check_io *io;
};

extern void dedup_check_endio(struct bio *clone);

extern void dedup_flush_endio(struct bio *clone); 
#endif /* DM_DEDUP_CHECK_CORRUPTION_H */

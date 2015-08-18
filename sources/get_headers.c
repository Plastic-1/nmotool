/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_headers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/18 16:56:58 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <libft.h>
#include <struct.h>

static void	get_fat_binary_headers(void *ptr, t_head *headers)
{
	struct fat_header		*fat_h;
	struct fat_arch			*fat_ar;
	struct mach_header_64	*machtmp;
	size_t					count;

	count = 0;
	fat_h = (struct fat_header *)ptr;
	fat_ar = (struct fat_arch *)(fat_h + 1);
	while (count < ft_revint32(fat_h->nfat_arch))
	{
		machtmp = (void *)((char *)ptr + ft_revint32(fat_ar->offset));
		if (machtmp->magic == MH_MAGIC_64
			&& machtmp->cputype == CPU_TYPE_X86_64)
			headers->mach64 = machtmp;
		else if (machtmp->magic == MH_MAGIC
				&& machtmp->cputype == CPU_TYPE_X86)
			headers->mach32 = (struct mach_header *)machtmp;
		fat_ar += 1;
		count++;
	}
}

static void	get_simple_binary_header(void *ptr, t_head *headers)
{
	struct mach_header_64	*machtmp;

	machtmp = (struct mach_header_64 *)ptr;
	if (machtmp->magic == MH_MAGIC_64
		&& machtmp->cputype == CPU_TYPE_X86_64)
		headers->mach64 = machtmp;
	else if (machtmp->magic == MH_MAGIC
			&& machtmp->cputype == CPU_TYPE_X86)
		headers->mach32 = (struct mach_header *)machtmp;
}

void		get_binary_headers(void *ptr, t_head *headers)
{
	struct fat_header		*fat_h;

	headers->mach64 = NULL;
	headers->mach32 = NULL;
	fat_h = (struct fat_header *)ptr;
	if (fat_h->magic == FAT_CIGAM)
		get_fat_binary_headers(ptr, headers);
	else
		get_simple_binary_header(ptr, headers);
}

# $NetBSD: Makefile,v 1.2 2019/02/17 04:05:49 rin Exp $

.include "../Makefile.inc"

.PATH:	${S}/dev/isa

KMOD=	finsio
IOCONF=	finsio.ioconf
SRCS=	finsio_isa.c

.include <bsd.kmodule.mk>

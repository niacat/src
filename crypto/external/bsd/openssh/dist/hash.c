/* $OpenBSD: hash.c,v 1.6 2019/11/29 00:11:21 djm Exp $ */
/*
 * Public domain. Author: Christian Weisgerber <naddy@openbsd.org>
 * API compatible reimplementation of function from nacl
 */
#include "includes.h"
__RCSID("$NetBSD: hash.c,v 1.7 2020/02/27 00:24:40 christos Exp $");

#include "crypto_api.h"

#include <stdarg.h>

#ifdef WITH_OPENSSL
#include <openssl/evp.h>

int
crypto_hash_sha512(unsigned char *out, const unsigned char *in,
    unsigned long long inlen)
{

	if (!EVP_Digest(in, inlen, out, NULL, EVP_sha512(), NULL))
		return -1;
	return 0;
}

#else
#include <sha2.h>

int
crypto_hash_sha512(unsigned char *out, const unsigned char *in,
    unsigned long long inlen)
{

	SHA2_CTX ctx;

	SHA512Init(&ctx);
	SHA512Update(&ctx, in, inlen);
	SHA512Final(out, &ctx);
	return 0;
}
#endif /* WITH_OPENSSL */

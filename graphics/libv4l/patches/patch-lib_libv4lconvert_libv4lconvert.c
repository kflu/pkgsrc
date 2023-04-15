$NetBSD: patch-lib_libv4lconvert_libv4lconvert.c,v 1.1 2023/03/13 13:18:35 wiz Exp $

Symbol doesn't exist in NetBSD 10.99.2.

--- lib/libv4lconvert/libv4lconvert.c.orig	2023-02-24 16:49:19.000000000 +0000
+++ lib/libv4lconvert/libv4lconvert.c
@@ -138,7 +138,9 @@ static const struct v4lconvert_pixfmt su
 	{ V4L2_PIX_FMT_KONICA420,	12,	 6,	 3,	1 },
 	{ V4L2_PIX_FMT_SN9C20X_I420,	12,	 6,	 3,	1 },
 	{ V4L2_PIX_FMT_M420,		12,	 6,	 3,	1 },
+#ifdef V4L2_PIX_FMT_NV12_16L16
 	{ V4L2_PIX_FMT_NV12_16L16,	12,	 6,	 3,	1 },
+#endif
 	{ V4L2_PIX_FMT_NV12,		12,	 6,	 3,	1 },
 	{ V4L2_PIX_FMT_CPIA1,		 0,	 6,	 3,	1 },
 	/* JPEG and variants */
@@ -915,6 +917,7 @@ static int v4lconvert_convert_pixfmt(str
 		break;
 	}
 
+#ifdef V4L2_PIX_FMT_NV12_16L16
 		/* Conexant cx2341x raw video macroblock format */
 	case V4L2_PIX_FMT_NV12_16L16:
 		switch (dest_pix_fmt) {
@@ -932,6 +935,7 @@ static int v4lconvert_convert_pixfmt(str
 			break;
 		}
 		break;
+#endif
 
 		/* NV12 formats */
 	case V4L2_PIX_FMT_NV12:

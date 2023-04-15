# $NetBSD: buildlink3.mk,v 1.1 2023/04/09 10:03:18 nros Exp $

BUILDLINK_TREE+=	qt6-qtgrpc

.if !defined(QT6_QTGRPC_BUILDLINK3_MK)
QT6_QTGRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtgrpc+=	qt6-qtgrpc>=6.5.0
BUILDLINK_PKGSRCDIR.qt6-qtgrpc?=	../../net/qt6-qtgrpc

BUILDLINK_FILES.qt6-qtgrpc+=	libexec/qtgrpcgen
BUILDLINK_FILES.qt6-qtgrpc+=	libexec/qtprotobufgen

.include "../../net/grpc/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTGRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtgrpc

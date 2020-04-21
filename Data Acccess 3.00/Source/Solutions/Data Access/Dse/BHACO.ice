// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef HELLO_ICE
#define HELLO_ICE

module BHAco
{

exception GenericError
{
    string reason;
};

exception PermissionDenied extends GenericError
{
};

exception NameInUse extends GenericError
{
};

exception NoSuchName extends GenericError
{
};

enum EFieldType
{
    FTFloat,
    FTInt,
    FTString,
    FTDateTime,
    FTBytes,
    FTBool,
    FTChar
};

sequence<byte> Buffers;

struct SFieldContent
{
    EFieldType fType;
    string     strValue;
    int        iValue;
    float      fValue;
    Buffers    buf;
};

dictionary<int, SFieldContent> RowDetail;

sequence<RowDetail> PackageDetail;

sequence<string> Warnings;

struct SMessageHeader
{
    short  nServiceCode;
    byte   nVersion;
    short  bodylength;
    string sessionid;
};

struct SDataPacket
{
    SMessageHeader msgHeader;
    PackageDetail  packet;
    Warnings       curWarnings;
    int            nRetCode;
};

interface Request
{
	SDataPacket RequestData(SDataPacket dp);
	
	["cpp:const"] idempotent void sayHello(int delay);
	
	void shutdown();
};

};

#endif



/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef LIGHTINK_MSGPACK_PACKER_CPP_

#define LIGHTINK_MSGPACK_PACKER_CPP_

#include <string.h>
#include <limits.h>
#include "Packer.h"

namespace LightInk
{
	template <typename TBuffer>
	inline Packer<TBuffer>::Packer() : m_buffer(NULL) 
	{
		LogTrace("Packer<TBuffer>::Packer()");
		LogTraceReturnVoid;
	}

	template <typename TBuffer>
	inline Packer<TBuffer>::Packer(TBuffer* b) : m_buffer(b) 
	{
		LogTrace("Packer<TBuffer>::Packer(TBuffer* b)");
		LogTraceReturnVoid;
	}

	template <typename TBuffer>
	inline Packer<TBuffer>::Packer(TBuffer& b) : m_buffer(&b)
	{
		LogTrace("Packer<TBuffer>::Packer(TBuffer& b)");
		LogTraceReturnVoid;
	}

	template <typename TBuffer>
	inline void Packer<TBuffer>::set_buffer(TBuffer * b)
	{
		LogTrace("void Packer<TBuffer>::set_buffer(TBuffer * b)");
		m_buffer = b;
		LogTraceReturnVoid;
	}
	template <typename TBuffer>
	inline void Packer<TBuffer>::set_buffer(TBuffer & b)
	{
		LogTrace("void Packer<TBuffer>::set_buffer(TBuffer & b)");
		m_buffer = &b;
		LogTraceReturnVoid;
	}
	template <typename TBuffer>
	inline TBuffer * Packer<TBuffer>::get_buffer()
	{
		LogTrace("TBuffer * Packer<TBuffer>::get_buffer()");
		LogTraceReturn(m_buffer);
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_uint8(TBuffer & buffer, uint8 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_uint8(TBuffer & buffer, uint8 d)");
		LogTraceReturn(pack_imp_uint8(buffer, d)); 
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_uint16(TBuffer & buffer, uint16 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_uint16(TBuffer & buffer, uint16 d)");
		LogTraceReturn(pack_imp_uint16(buffer, d)); 
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_uint32(TBuffer & buffer, uint32 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_uint32(TBuffer & buffer, uint32 d)");
		LogTraceReturn(pack_imp_uint32(buffer, d)); 
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_uint64(TBuffer & buffer, uint64 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_uint64(TBuffer & buffer, uint64 d)");
		LogTraceReturn(pack_imp_uint64(buffer, d)); 
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_int8(TBuffer & buffer, int8 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_int8(TBuffer & buffer, int8 d)");
		LogTraceReturn(pack_imp_int8(buffer, d)); 
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_int16(TBuffer & buffer, int16 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_int16(TBuffer & buffer, int16 d)");
		LogTraceReturn(pack_imp_int16(buffer, d)); 
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_int32(TBuffer & buffer, int32 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_int32(TBuffer & buffer, int32 d)");
		LogTraceReturn(pack_imp_int32(buffer, d)); 
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_int64(TBuffer & buffer, int64 d)
	{ 
		LogTrace("RuntimeError Packer<TBuffer>::pack_int64(TBuffer & buffer, int64 d)");
		LogTraceReturn(pack_imp_int64(buffer, d)); 
	}


	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_uint8(TBuffer & buffer, uint8 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_uint8(TBuffer & buffer, uint8 d)");
		char buf[2] = {static_cast<char>(_msgpack_head_uint8), take8_8(d)};
		LogTraceReturn(buffer.write(buf, 2));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_uint16(TBuffer & buffer, uint16 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_uint16(TBuffer & buffer, uint16 d)");
		char buf[3];
		buf[0] = static_cast<char>(_msgpack_head_uint16); _msgpack_store16(&buf[1], d);
		LogTraceReturn(buffer.write(buf, 3));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_uint32(TBuffer & buffer, uint32 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_uint32(TBuffer & buffer, uint32 d)");
		char buf[5];
		buf[0] = static_cast<char>(_msgpack_head_uint32); _msgpack_store32(&buf[1], d);
		LogTraceReturn(buffer.write(buf, 5));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_uint64(TBuffer & buffer, uint64 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_uint64(TBuffer & buffer, uint64 d)");
		char buf[9];
		buf[0] = static_cast<char>(_msgpack_head_uint64); _msgpack_store64(&buf[1], d);
		LogTraceReturn(buffer.write(buf, 9));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_int8(TBuffer & buffer, int8 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_int8(TBuffer & buffer, int8 d)");
		char buf[2] = {static_cast<char>(_msgpack_head_int8), take8_8(d)};
		LogTraceReturn(buffer.write(buf, 2));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_int16(TBuffer & buffer, int16 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_int16(TBuffer & buffer, int16 d)");
		char buf[3];
		buf[0] = static_cast<char>(_msgpack_head_int16); _msgpack_store16(&buf[1], d);
		LogTraceReturn(buffer.write(buf, 3));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_int32(TBuffer & buffer, int32 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_int32(TBuffer & buffer, int32 d)");
		char buf[5];
		buf[0] = static_cast<char>(_msgpack_head_int32); _msgpack_store32(&buf[1], d);
		LogTraceReturn(buffer.write(buf, 5));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_fix_int64(TBuffer & buffer, int64 d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_fix_int64(TBuffer & buffer, int64 d)");
		char buf[9];
		buf[0] = static_cast<char>(_msgpack_head_int64); _msgpack_store64(&buf[1], d);
		LogTraceReturn(buffer.write(buf, 9));
	}


	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_char(TBuffer & buffer, char d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_char(TBuffer & buffer, char d)");
#if defined(CHAR_MIN)
#if CHAR_MIN < 0
		LogTraceReturn(pack_imp_int8(buffer, d));
#else
		LogTraceReturn(pack_imp_uint8(buffer, d));
#endif
#else
#error CHAR_MIN is not defined
#endif
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_signed_char(TBuffer & buffer, signed char d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_signed_char(TBuffer & buffer, signed char d)");
		LogTraceReturn(pack_imp_int8(buffer, d));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_short(TBuffer & buffer, short d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_short(TBuffer & buffer, short d)");
#if defined(SIZEOF_SHORT)
#if SIZEOF_SHORT == 2
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif SIZEOF_SHORT == 4
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#elif defined(SHRT_MAX)
#if SHRT_MAX == 0x7fff
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif SHRT_MAX == 0x7fffffff
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#else
		if(sizeof(short) == 2) {
			LogTraceReturn(pack_imp_int16(buffer, d));
		} else if(sizeof(short) == 4) {
			LogTraceReturn(pack_imp_int32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_int64(buffer, d));
		}
#endif
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_int(TBuffer & buffer, int d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_int(TBuffer & buffer, int d)");
#if defined(SIZEOF_INT)
#if SIZEOF_INT == 2
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif SIZEOF_INT == 4
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#elif defined(INT_MAX)
#if INT_MAX == 0x7fff
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif INT_MAX == 0x7fffffff
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#else
		if(sizeof(int) == 2) {
			LogTraceReturn(pack_imp_int16(buffer, d));
		} else if(sizeof(int) == 4) {
			LogTraceReturn(pack_imp_int32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_int64(buffer, d));
		}
#endif
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_long(TBuffer & buffer, long d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_long(TBuffer & buffer, long d)");
#if defined(SIZEOF_LONG)
#if SIZEOF_LONG == 2
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif SIZEOF_LONG == 4
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#elif defined(LONG_MAX)
#if LONG_MAX == 0x7fffL
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif LONG_MAX == 0x7fffffffL
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#else
		if(sizeof(long) == 2) {
			LogTraceReturn(pack_imp_int16(buffer, d));
		} else if(sizeof(long) == 4) {
			LogTraceReturn(pack_imp_int32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_int64(buffer, d));
		}
#endif
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_long_long(TBuffer & buffer, long long d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_long_long(TBuffer & buffer, long long d)");
#if defined(SIZEOF_LONG_LONG)
#if SIZEOF_LONG_LONG == 2
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif SIZEOF_LONG_LONG == 4
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#elif defined(LLONG_MAX)
#if LLONG_MAX == 0x7fffL
		LogTraceReturn(pack_imp_int16(buffer, d));
#elif LLONG_MAX == 0x7fffffffL
		LogTraceReturn(pack_imp_int32(buffer, d));
#else
		LogTraceReturn(pack_imp_int64(buffer, d));
#endif

#else
		if(sizeof(long long) == 2) {
			LogTraceReturn(pack_imp_int16(buffer, d));
		} else if(sizeof(long long) == 4) {
			LogTraceReturn(pack_imp_int32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_int64(buffer, d));
		}
#endif
	}


	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_unsigned_char(TBuffer & buffer, unsigned char d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_unsigned_char(TBuffer & buffer, unsigned char d)");
		LogTraceReturn(pack_imp_uint8(buffer, d));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_unsigned_short(TBuffer & buffer, unsigned short d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_unsigned_short(TBuffer & buffer, unsigned short d)");
#if defined(SIZEOF_SHORT)
#if SIZEOF_SHORT == 2
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif SIZEOF_SHORT == 4
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#elif defined(USHRT_MAX)
#if USHRT_MAX == 0xffffU
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif USHRT_MAX == 0xffffffffU
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#else
		if(sizeof(unsigned short) == 2) {
			LogTraceReturn(pack_imp_uint16(buffer, d));
		} else if(sizeof(unsigned short) == 4) {
			LogTraceReturn(pack_imp_uint32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_uint64(buffer, d));
		}
#endif
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_unsigned_int(TBuffer & buffer, unsigned int d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_unsigned_int(TBuffer & buffer, unsigned int d)");
#if defined(SIZEOF_INT)
#if SIZEOF_INT == 2
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif SIZEOF_INT == 4
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#elif defined(UINT_MAX)
#if UINT_MAX == 0xffffU
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif UINT_MAX == 0xffffffffU
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#else
		if(sizeof(unsigned int) == 2) {
			LogTraceReturn(pack_imp_uint16(buffer, d));
		} else if(sizeof(unsigned int) == 4) {
			LogTraceReturn(pack_imp_uint32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_uint64(buffer, d));
		}
#endif
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_unsigned_long(TBuffer & buffer, unsigned long d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_unsigned_long(TBuffer & buffer, unsigned long d)");
#if defined(SIZEOF_LONG)
#if SIZEOF_LONG == 2
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif SIZEOF_LONG == 4
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#elif defined(ULONG_MAX)
#if ULONG_MAX == 0xffffUL
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif ULONG_MAX == 0xffffffffUL
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#else
		if(sizeof(unsigned long) == 2) {
			LogTraceReturn(pack_imp_uint16(buffer, d));
		} else if(sizeof(unsigned long) == 4) {
			LogTraceReturn(pack_imp_uint32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_uint64(buffer, d));
		}
#endif
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_unsigned_long_long(TBuffer & buffer, unsigned long long d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_unsigned_long_long(TBuffer & buffer, unsigned long long d)");
#if defined(SIZEOF_LONG_LONG)
#if SIZEOF_LONG_LONG == 2
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif SIZEOF_LONG_LONG == 4
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#elif defined(ULLONG_MAX)
#if ULLONG_MAX == 0xffffUL
		LogTraceReturn(pack_imp_uint16(buffer, d));
#elif ULLONG_MAX == 0xffffffffUL
		LogTraceReturn(pack_imp_uint32(buffer, d));
#else
		LogTraceReturn(pack_imp_uint64(buffer, d));
#endif

#else
		if(sizeof(unsigned long long) == 2) {
			LogTraceReturn(pack_imp_uint16(buffer, d));
		} else if(sizeof(unsigned long long) == 4) {
			LogTraceReturn(pack_imp_uint32(buffer, d));
		} else {
			LogTraceReturn(pack_imp_uint64(buffer, d));
		}
#endif
	}


	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_float(TBuffer & buffer, float d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_float(TBuffer & buffer, float d)");
		union { float f; uint32 i; } mem;
		mem.f = d;
		char buf[5];
		buf[0] = static_cast<char>(_msgpack_head_float32); _msgpack_store32(&buf[1], mem.i);
		LogTraceReturn(buffer.write(buf, 5));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_double(TBuffer & buffer, double d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_double(TBuffer & buffer, double d)");
		union { double f; uint64 i; } mem;
		mem.f = d;
		char buf[9];
		buf[0] = static_cast<char>(_msgpack_head_float64);
#if defined(__arm__) && !(__ARM_EABI__) // arm-oabi
		// https://github.com/msgpack/msgpack-perl/pull/1
		mem.i = (mem.i & 0xFFFFFFFFUL) << 32UL | (mem.i >> 32UL);
#endif
		_msgpack_store64(&buf[1], mem.i);
		LogTraceReturn(buffer.write(buf, 9));
	}


	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_nil(TBuffer & buffer)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_nil(TBuffer & buffer)");
		const char d = static_cast<char>(_msgpack_head_nil);
		LogTraceReturn(buffer.write(&d, 1));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_bool(TBuffer & buffer, bool d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_bool(TBuffer & buffer, bool d)");
		if (d)
		{
			const char t = static_cast<char>(_msgpack_head_true);
			LogTraceReturn(buffer.write(&t, 1));
		}
		else
		{
			const char t = static_cast<char>(_msgpack_head_false);
			LogTraceReturn(buffer.write(&t, 1));
		}
	}


	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_array(TBuffer & buffer, uint32 n)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_array(TBuffer & buffer, uint32 n)");
		if(n < 16) {
			char d = static_cast<char>(_msgpack_head_fixarray_from | n);
			LogTraceReturn(buffer.write(&d, 1));
		} else if(n < 65536) {
			char buf[3];
			buf[0] = static_cast<char>(_msgpack_head_array16); _msgpack_store16(&buf[1], static_cast<uint16>(n));
			LogTraceReturn(buffer.write(buf, 3));
		} else {
			char buf[5];
			buf[0] = static_cast<char>(_msgpack_head_array32); _msgpack_store32(&buf[1], static_cast<uint32>(n));
			LogTraceReturn(buffer.write(buf, 5));
		}
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_map(TBuffer & buffer, uint32 n)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_map(TBuffer & buffer, uint32 n)");
		if(n < 16) {
			unsigned char d = static_cast<unsigned char>(_msgpack_head_fixmap_from | n);
			char buf = take8_8(d);
			LogTraceReturn(buffer.write(&buf, 1));
		} else if(n < 65536) {
			char buf[3];
			buf[0] = static_cast<char>(_msgpack_head_map16); _msgpack_store16(&buf[1], static_cast<uint16>(n));
			LogTraceReturn(buffer.write(buf, 3));
		} else {
			char buf[5];
			buf[0] = static_cast<char>(_msgpack_head_map32); _msgpack_store32(&buf[1], static_cast<uint32>(n));
			LogTraceReturn(buffer.write(buf, 5));
		}
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_str(TBuffer & buffer, uint32 l)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_str(TBuffer & buffer, uint32 l)");
		if(l < 32) {
			unsigned char d = _msgpack_head_fixstr_from | static_cast<uint8>(l);
			char buf = take8_8(d);
			LogTraceReturn(buffer.write(&buf, 1));
		} else if(l < 256) {
			char buf[2];
			buf[0] = static_cast<char>(_msgpack_head_str8); buf[1] = static_cast<uint8>(l);
			LogTraceReturn(buffer.write(buf, 2));
		} else if(l < 65536) {
			char buf[3];
			buf[0] = static_cast<char>(_msgpack_head_str16); _msgpack_store16(&buf[1], static_cast<uint16>(l));
			LogTraceReturn(buffer.write(buf, 3));
		} else {
			char buf[5];
			buf[0] = static_cast<char>(_msgpack_head_str32); _msgpack_store32(&buf[1], static_cast<uint32>(l));
			LogTraceReturn(buffer.write(buf, 5));
		}
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_str_body(TBuffer & buffer, const char* b, uint32 l)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_str_body(TBuffer & buffer, const char* b, uint32 l)");
		LogTraceReturn(buffer.write(b, l));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_str_string(TBuffer & buffer, const std::string & s)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_str_string(TBuffer & buffer, const std::string & s)");
		RuntimeError err = pack_str(buffer, s.size());
		if (err != RE_Success)
		{
			LogTraceReturn(err);
		}
		LogTraceReturn(buffer.write(s));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_bin(TBuffer & buffer, uint32 l)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_bin(TBuffer & buffer, uint32 l)");
		if(l < 256) {
			char buf[2];
			buf[0] = static_cast<char>(_msgpack_head_bin8); buf[1] = static_cast<uint8>(l);
			LogTraceReturn(buffer.write(buf, 2));
		} else if(l < 65536) {
			char buf[3];
			buf[0] = static_cast<char>(_msgpack_head_bin16); _msgpack_store16(&buf[1], static_cast<uint16>(l));
			LogTraceReturn(buffer.write(buf, 3));
		} else {
			char buf[5];
			buf[0] = static_cast<char>(_msgpack_head_bin32); _msgpack_store32(&buf[1], static_cast<uint32>(l));
			LogTraceReturn(buffer.write(buf, 5));
		}
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_bin_body(TBuffer & buffer, const char* b, uint32 l)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_bin_body(TBuffer & buffer, const char* b, uint32 l)");
		LogTraceReturn(buffer.write(b, l));
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_ext(TBuffer & buffer, uint32 l, int8 type)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_ext(TBuffer & buffer, uint32 l, int8 type)");
		switch(l) {
		case 1: {
			char buf[2];
			buf[0] = static_cast<char>(_msgpack_head_fixext1);
			buf[1] = static_cast<char>(type);
			LogTraceReturn(buffer.write(buf, 2));
				} break;
		case 2: {
			char buf[2];
			buf[0] = static_cast<char>(_msgpack_head_fixext2);
			buf[1] = static_cast<char>(type);
			LogTraceReturn(buffer.write(buf, 2));
				} break;
		case 4: {
			char buf[2];
			buf[0] = static_cast<char>(_msgpack_head_fixext4);
			buf[1] = static_cast<char>(type);
			LogTraceReturn(buffer.write(buf, 2));
				} break;
		case 8: {
			char buf[2];
			buf[0] = static_cast<char>(_msgpack_head_fixext8);
			buf[1] = static_cast<char>(type);
			LogTraceReturn(buffer.write(buf, 2));
				} break;
		case 16: {
			char buf[2];
			buf[0] = static_cast<char>(_msgpack_head_fixext16);
			buf[1] = static_cast<char>(type);
			LogTraceReturn(buffer.write(buf, 2));
				 } break;
		default:
			if(l < 256) {
				char buf[3];
				buf[0] = static_cast<char>(_msgpack_head_ext8);
				buf[1] = static_cast<char>(l);
				buf[2] = static_cast<char>(type);
				LogTraceReturn(buffer.write(buf, 3));
			} else if(l < 65536) {
				char buf[4];
				buf[0] = static_cast<char>(_msgpack_head_ext16);
				_msgpack_store16(&buf[1], static_cast<uint16>(l));
				buf[3] = static_cast<char>(type);
				LogTraceReturn(buffer.write(buf, 4));
			} else {
				char buf[6];
				buf[0] = static_cast<char>(_msgpack_head_ext32);
				_msgpack_store32(&buf[1], static_cast<uint32>(l));
				buf[5] = static_cast<char>(type);
				LogTraceReturn(buffer.write(buf, 6));
			}
			break;
		}
		LogTraceReturn(RE_Msgpack_TypeError);
	}

	template <typename TBuffer>
	inline RuntimeError Packer<TBuffer>::pack_ext_body(TBuffer & buffer, const char* b, uint32 l)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_ext_body(TBuffer & buffer, const char* b, uint32 l)");
		LogTraceReturn(buffer.write(b, l));
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_uint8(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_uint8(TBuffer & buffer, T d)");
		if(d < (1<<7)) {
			/* fixnum */
			char buf = take8_8(d);
			LogTraceReturn(buffer.write(&buf, 1));
		} else {
			/* unsigned 8 */
			char buf[2] = {static_cast<char>(_msgpack_head_uint8), take8_8(d)};
			LogTraceReturn(buffer.write(buf, 2));
		}
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_uint16(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_uint16(TBuffer & buffer, T d)");
		if(d < (1<<7)) {
			/* fixnum */
			char buf = take8_16(d);
			LogTraceReturn(buffer.write(&buf, 1));
		} else if(d < (1<<8)) {
			/* unsigned 8 */
			char buf[2] = {static_cast<char>(_msgpack_head_uint8), take8_16(d)};
			LogTraceReturn(buffer.write(buf, 2));
		} else {
			/* unsigned 16 */
			char buf[3];
			buf[0] = static_cast<char>(_msgpack_head_uint16); _msgpack_store16(&buf[1], static_cast<uint16>(d));
			LogTraceReturn(buffer.write(buf, 3));
		}
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_uint32(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_uint32(TBuffer & buffer, T d)");
		if(d < (1<<8)) {
			if(d < (1<<7)) {
				/* fixnum */
				char buf = take8_32(d);
				LogTraceReturn(buffer.write(&buf, 1));
			} else {
				/* unsigned 8 */
				char buf[2] = {static_cast<char>(_msgpack_head_uint8), take8_32(d)};
				LogTraceReturn(buffer.write(buf, 2));
			}
		} else {
			if(d < (1<<16)) {
				/* unsigned 16 */
				char buf[3];
				buf[0] = static_cast<char>(_msgpack_head_uint16); _msgpack_store16(&buf[1], static_cast<uint16>(d));
				LogTraceReturn(buffer.write(buf, 3));
			} else {
				/* unsigned 32 */
				char buf[5];
				buf[0] = static_cast<char>(_msgpack_head_uint32); _msgpack_store32(&buf[1], static_cast<uint32>(d));
				LogTraceReturn(buffer.write(buf, 5));
			}
		}
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_uint64(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_uint64(TBuffer & buffer, T d)");
		if(d < (1ULL<<8)) {
			if(d < (1ULL<<7)) {
				/* fixnum */
				char buf = take8_64(d);
				LogTraceReturn(buffer.write(&buf, 1));
			} else {
				/* unsigned 8 */
				char buf[2] = {static_cast<char>(_msgpack_head_uint8), take8_64(d)};
				LogTraceReturn(buffer.write(buf, 2));
			}
		} else {
			if(d < (1ULL<<16)) {
				/* unsigned 16 */
				char buf[3];
				buf[0] = static_cast<char>(_msgpack_head_uint16); _msgpack_store16(&buf[1], static_cast<uint16>(d));
				LogTraceReturn(buffer.write(buf, 3));
			} else if(d < (1ULL<<32)) {
				/* unsigned 32 */
				char buf[5];
				buf[0] = static_cast<char>(_msgpack_head_uint32); _msgpack_store32(&buf[1], static_cast<uint32>(d));
				LogTraceReturn(buffer.write(buf, 5));
			} else {
				/* unsigned 64 */
				char buf[9];
				buf[0] = static_cast<char>(_msgpack_head_uint64); _msgpack_store64(&buf[1], d);
				LogTraceReturn(buffer.write(buf, 9));
			}
		}
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_int8(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_int8(TBuffer & buffer, T d)");
		if(d < -(1<<5)) {
			/* signed 8 */
			char buf[2] = {static_cast<char>(_msgpack_head_int8), take8_8(d)};
			LogTraceReturn(buffer.write(buf, 2));
		} else {
			/* fixnum */
			char buf = take8_8(d);
			LogTraceReturn(buffer.write(&buf, 1));
		}
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_int16(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_int16(TBuffer & buffer, T d)");
		if(d < -(1<<5)) {
			if(d < -(1<<7)) {
				/* signed 16 */
				char buf[3];
				buf[0] = static_cast<char>(_msgpack_head_int16); _msgpack_store16(&buf[1], static_cast<int16>(d));
				LogTraceReturn(buffer.write(buf, 3));
			} else {
				/* signed 8 */
				char buf[2] = {static_cast<char>(_msgpack_head_int8), take8_16(d)};
				LogTraceReturn(buffer.write(buf, 2));
			}
		} else if(d < (1<<7)) {
			/* fixnum */
			char buf = take8_16(d);
			LogTraceReturn(buffer.write(&buf, 1));
		} else {
			if(d < (1<<8)) {
				/* unsigned 8 */
				char buf[2] = {static_cast<char>(_msgpack_head_uint8), take8_16(d)};
				LogTraceReturn(buffer.write(buf, 2));
			} else {
				/* unsigned 16 */
				char buf[3];
				buf[0] = static_cast<char>(_msgpack_head_uint16); _msgpack_store16(&buf[1], static_cast<uint16>(d));
				LogTraceReturn(buffer.write(buf, 3));
			}
		}
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_int32(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_int32(TBuffer & buffer, T d)");
		if(d < -(1<<5)) {
			if(d < -(1<<15)) {
				/* signed 32 */
				char buf[5];
				buf[0] = static_cast<char>(_msgpack_head_int32); _msgpack_store32(&buf[1], static_cast<int32>(d));
				LogTraceReturn(buffer.write(buf, 5));
			} else if(d < -(1<<7)) {
				/* signed 16 */
				char buf[3];
				buf[0] = static_cast<char>(_msgpack_head_int16); _msgpack_store16(&buf[1], static_cast<int16>(d));
				LogTraceReturn(buffer.write(buf, 3));
			} else {
				/* signed 8 */
				char buf[2] = { static_cast<char>(_msgpack_head_int8), take8_32(d)};
				LogTraceReturn(buffer.write(buf, 2));
			}
		} else if(d < (1<<7)) {
			/* fixnum */
			char buf = take8_32(d);
			LogTraceReturn(buffer.write(&buf, 1));
		} else {
			if(d < (1<<8)) {
				/* unsigned 8 */
				char buf[2] = { static_cast<char>(_msgpack_head_uint8), take8_32(d)};
				LogTraceReturn(buffer.write(buf, 2));
			} else if(d < (1<<16)) {
				/* unsigned 16 */
				char buf[3];
				buf[0] = static_cast<char>(_msgpack_head_uint16); _msgpack_store16(&buf[1], static_cast<uint16>(d));
				LogTraceReturn(buffer.write(buf, 3));
			} else {
				/* unsigned 32 */
				char buf[5];
				buf[0] = static_cast<char>(_msgpack_head_uint32); _msgpack_store32(&buf[1], static_cast<uint32>(d));
				LogTraceReturn(buffer.write(buf, 5));
			}
		}
	}

	template <typename TBuffer>
	template <typename T>
	inline RuntimeError Packer<TBuffer>::pack_imp_int64(TBuffer & buffer, T d)
	{
		LogTrace("RuntimeError Packer<TBuffer>::pack_imp_int64(TBuffer & buffer, T d)");
		if(d < -(1LL<<5)) {
			if(d < -(1LL<<15)) {
				if(d < -(1LL<<31)) {
					/* signed 64 */
					char buf[9];
					buf[0] = static_cast<char>(_msgpack_head_int64); _msgpack_store64(&buf[1], d);
					LogTraceReturn(buffer.write(buf, 9));
				} else {
					/* signed 32 */
					char buf[5];
					buf[0] = static_cast<char>(_msgpack_head_int32); _msgpack_store32(&buf[1], static_cast<int32>(d));
					LogTraceReturn(buffer.write(buf, 5));
				}
			} else {
				if(d < -(1<<7)) {
					/* signed 16 */
					char buf[3];
					buf[0] = static_cast<char>(_msgpack_head_int16); _msgpack_store16(&buf[1], static_cast<int16>(d));
					LogTraceReturn(buffer.write(buf, 3));
				} else {
					/* signed 8 */
					char buf[2] = {static_cast<char>(_msgpack_head_int8), take8_64(d)};
					LogTraceReturn(buffer.write(buf, 2));
				}
			}
		} else if(d < (1<<7)) {
			/* fixnum */
			char buf = take8_64(d);
			LogTraceReturn(buffer.write(&buf, 1));
		} else {
			if(d < (1LL<<16)) {
				if(d < (1<<8)) {
					/* unsigned 8 */
					char buf[2] = {static_cast<char>(_msgpack_head_uint8), take8_64(d)};
					LogTraceReturn(buffer.write(buf, 2));
				} else {
					/* unsigned 16 */
					char buf[3];
					buf[0] = static_cast<char>(_msgpack_head_uint16); _msgpack_store16(&buf[1], static_cast<uint16>(d));
					LogTraceReturn(buffer.write(buf, 3));
				}
			} else {
				if(d < (1LL<<32)) {
					/* unsigned 32 */
					char buf[5];
					buf[0] = static_cast<char>(_msgpack_head_uint32); _msgpack_store32(&buf[1], static_cast<uint32>(d));
					LogTraceReturn(buffer.write(buf, 5));
				} else {
					/* unsigned 64 */
					char buf[9];
					buf[0] = static_cast<char>(_msgpack_head_uint64); _msgpack_store64(&buf[1], d);
					LogTraceReturn(buffer.write(buf, 9));
				}
			}
		}
	}
}


#endif



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


#ifndef LIGHTINK_MSGPACK_UNPACKER_H_
#define LIGHTINK_MSGPACK_UNPACKER_H_

#include "Sysdep.h"
#include "PackBuffer.h"
#include "Common/TypeTool.h"
#include "Common/RuntimeError.h"

namespace LightInk
{
	template<typename TBuffer>
	class LIGHTINK_TEMPLATE_DECL Unpacker
	{
	public:
		Unpacker();
		Unpacker(TBuffer* b);
		Unpacker(TBuffer& b);
		void set_buffer(TBuffer * b);
		void set_buffer(TBuffer & b);
		TBuffer * get_buffer();

	public:
		uint8 get_pack_type() { LogTrace("uint8 get_pack_type()"); LogTraceReturn(get_pack_type(*m_buffer)); }

		uint32 clear_pack_type(uint8 packType) { LogTrace("uint32 clear_pack_type(uint8 packType)"); LogTraceReturn(clear_pack_type(*m_buffer, packType)); }

		RuntimeError unpack_uint8(uint8 & d){ LogTrace("RuntimeError unpack_uint8(uint8 & d)"); LogTraceReturn(unpack_uint8(*m_buffer, d)); }
		RuntimeError unpack_uint16(uint16 & d) { LogTrace("RuntimeError unpack_uint16(uint16 & d)"); LogTraceReturn(unpack_uint16(*m_buffer, d)); }
		RuntimeError unpack_uint32(uint32 & d) { LogTrace("RuntimeError unpack_uint32(uint32 & d)"); LogTraceReturn(unpack_uint32(*m_buffer, d)); }
		RuntimeError unpack_uint64(uint64 & d) { LogTrace("RuntimeError unpack_uint64(uint64 & d)"); LogTraceReturn(unpack_uint64(*m_buffer, d)); }
		RuntimeError unpack_int8(int8 & d) { LogTrace("RuntimeError unpack_int8(int8 & d)"); LogTraceReturn(unpack_int8(*m_buffer ,d)); }
		RuntimeError unpack_int16(int16 & d) { LogTrace("RuntimeError unpack_int16(int16 & d)"); LogTraceReturn(unpack_int16(*m_buffer, d)); }
		RuntimeError unpack_int32(int32 & d) { LogTrace("RuntimeError unpack_int32(int32 & d)"); LogTraceReturn(unpack_int32(*m_buffer, d)); }
		RuntimeError unpack_int64(int64 & d) { LogTrace("RuntimeError unpack_int64(int64 & d)"); LogTraceReturn(unpack_int64(*m_buffer, d)); }

		RuntimeError unpack_char(char & d) { LogTrace("RuntimeError unpack_char(char & d)"); LogTraceReturn(unpack_char(*m_buffer, d)); }
		RuntimeError unpack_signed_char(signed char & d) { LogTrace("RuntimeError unpack_signed_char(signed char & d)"); LogTraceReturn(unpack_signed_char(*m_buffer, d)); }
		RuntimeError unpack_short(short & d)  { LogTrace("RuntimeError unpack_short(short & d)"); LogTraceReturn(unpack_short(*m_buffer, d)); }
		RuntimeError unpack_int(int & d) { LogTrace("RuntimeError unpack_int(int & d)"); LogTraceReturn(unpack_int(*m_buffer, d)); }
		RuntimeError unpack_long(long & d) { LogTrace("RuntimeError unpack_long(long & d)"); LogTraceReturn(unpack_long(*m_buffer, d)); }
		RuntimeError unpack_long_long(long long & d) { LogTrace("RuntimeError unpack_long_long(long long & d)"); LogTraceReturn(unpack_long_long(*m_buffer, d)); }
		RuntimeError unpack_unsigned_char(unsigned char & d) { LogTrace("RuntimeError unpack_unsigned_char(unsigned char & d)"); LogTraceReturn(unpack_unsigned_char(*m_buffer, d)); }
		RuntimeError unpack_unsigned_short(unsigned short & d) { LogTrace("RuntimeError unpack_unsigned_short(unsigned short & d)"); LogTraceReturn(unpack_unsigned_short(*m_buffer, d)); }
		RuntimeError unpack_unsigned_int(unsigned int & d) { LogTrace("RuntimeError unpack_unsigned_int(unsigned int & d)"); LogTraceReturn(unpack_unsigned_int(*m_buffer, d)); }
		RuntimeError unpack_unsigned_long(unsigned long & d) { LogTrace("RuntimeError unpack_unsigned_long(unsigned long & d)"); LogTraceReturn(unpack_unsigned_long(*m_buffer, d)); }
		RuntimeError unpack_unsigned_long_long(unsigned long long & d) { LogTrace("RuntimeError unpack_unsigned_long_long(unsigned long long & d)"); LogTraceReturn(unpack_unsigned_long_long(*m_buffer, d)); }

		RuntimeError unpack_float(float & d) { LogTrace("RuntimeError unpack_float(float & d)"); LogTraceReturn(unpack_float(*m_buffer, d)); }
		RuntimeError unpack_double(double & d) { LogTrace("RuntimeError unpack_double(double & d)"); LogTraceReturn(unpack_double(*m_buffer, d)); }

		RuntimeError unpack_nil() { LogTrace("RuntimeError unpack_nil()"); LogTraceReturn(unpack_nil(*m_buffer)); }
		RuntimeError unpack_bool(bool & d) { LogTrace("RuntimeError unpack_bool(bool & d)"); LogTraceReturn(unpack_bool(*m_buffer, d)); }

		RuntimeError unpack_array(uint32 & l) { LogTrace("RuntimeError unpack_array(uint32 & l)"); LogTraceReturn(unpack_array(*m_buffer, l)); }

		RuntimeError unpack_map(uint32 & l) { LogTrace("RuntimeError unpack_map(uint32 & l)"); LogTraceReturn(unpack_map(*m_buffer, l)); }

		RuntimeError unpack_str(uint32 & l) { LogTrace("RuntimeError unpack_str(uint32 & l)"); LogTraceReturn(unpack_str(*m_buffer, l)); }
		RuntimeError unpack_str_body(const char* b, uint32 l) { LogTrace("RuntimeError unpack_str_body(const char* b, uint32 l)"); LogTraceReturn(unpack_str_body(*m_buffer, b, l)); }

		RuntimeError unpack_str_string(std::string & s) { LogTrace("RuntimeError unpack_str_string(std::string & s)"); LogTraceReturn(unpack_str_string(*m_buffer, s)); }

		RuntimeError unpack_str_simple(char ** b, uint32 l) { LogTrace("RuntimeError unpack_str_simple(char ** b, uint32 l)"); LogTraceReturn(unpack_str_simple(*m_buffer, b, l)); }

		RuntimeError unpack_bin(uint32 & l) { LogTrace("RuntimeError unpack_bin(uint32 & l)"); LogTraceReturn(unpack_bin(*m_buffer, l)); }
		RuntimeError unpack_bin_body(const char* b, uint32 l) { LogTrace("RuntimeError unpack_bin_body(const char* b, uint32 l)"); LogTraceReturn(unpack_bin_body(*m_buffer, b, l)); }

		RuntimeError unpack_ext(uint32 & l, int8 & type) { LogTrace("RuntimeError unpack_ext(uint32 & l, int8 & type)"); LogTraceReturn(unpack_ext(*m_buffer, l, type)); }
		RuntimeError unpack_ext_body(const char* b, uint32 l) { LogTrace("RuntimeError unpack_ext_body(const char* b, uint32 l)"); LogTraceReturn(unpack_ext_body(*m_buffer, b, l)); }

	public: //static func

		static uint8 get_pack_type(TBuffer & buffer);

		static uint32 clear_pack_type(TBuffer & buffer, uint8 packType);

		static RuntimeError unpack_uint8(TBuffer & buffer, uint8 & d);
		static RuntimeError unpack_uint16(TBuffer & buffer, uint16 & d);
		static RuntimeError unpack_uint32(TBuffer & buffer, uint32 & d);
		static RuntimeError unpack_uint64(TBuffer & buffer, uint64 & d);
		static RuntimeError unpack_int8(TBuffer & buffer, int8 & d);
		static RuntimeError unpack_int16(TBuffer & buffer, int16 & d);
		static RuntimeError unpack_int32(TBuffer & buffer, int32 & d);
		static RuntimeError unpack_int64(TBuffer & buffer, int64 & d);

		static RuntimeError unpack_char(TBuffer & buffer, char  & d);
		static RuntimeError unpack_signed_char(TBuffer & buffer, signed char & d);
		static RuntimeError unpack_short(TBuffer & buffer, short & d);
		static RuntimeError unpack_int(TBuffer & buffer, int & d);
		static RuntimeError unpack_long(TBuffer & buffer, long & d);
		static RuntimeError unpack_long_long(TBuffer & buffer, long long & d);
		static RuntimeError unpack_unsigned_char(TBuffer & buffer, unsigned char & d);
		static RuntimeError unpack_unsigned_short(TBuffer & buffer, unsigned short & d);
		static RuntimeError unpack_unsigned_int(TBuffer & buffer, unsigned int & d);
		static RuntimeError unpack_unsigned_long(TBuffer & buffer, unsigned long & d);
		static RuntimeError unpack_unsigned_long_long(TBuffer & buffer, unsigned long long & d);

		static RuntimeError unpack_float(TBuffer & buffer, float & d);
		static RuntimeError unpack_double(TBuffer & buffer, double & d);

		static RuntimeError unpack_nil(TBuffer & buffer);
		static RuntimeError unpack_bool(TBuffer & buffer, bool & d);

		static RuntimeError unpack_array(TBuffer & buffer, uint32 & l);

		static RuntimeError unpack_map(TBuffer & buffer, uint32 & l);

		static RuntimeError unpack_str(TBuffer & buffer, uint32 & l);
		static RuntimeError unpack_str_body(TBuffer & buffer, char * b, uint32 l);

		static RuntimeError unpack_str_string(TBuffer & buffer, std::string & s);

		static RuntimeError unpack_str_simple(TBuffer & buffer, char ** b, uint32 & l);

		static RuntimeError unpack_bin(TBuffer & buffer, uint32  & l);
		static RuntimeError unpack_bin_body(TBuffer & buffer, char * b, uint32 l);

		static RuntimeError unpack_ext(TBuffer & buffer, uint32 & l, int8 & type);
		static RuntimeError unpack_ext_body(TBuffer & buffer, char * b, uint32 l);

	private:
		template <typename T>
		static RuntimeError unpack_imp_uint8(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(uint8), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_uint16(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(uint16), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_uint32(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(uint32), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_uint64(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(uint64), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_int8(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(int8), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_int16(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(int16), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_int32(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(int32), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_int64(TBuffer & buffer, typename enable_if<sizeof(T) == sizeof(int64), T>::type & d, uint8 header);

		template <typename T>
		static RuntimeError unpack_imp_check_int(TBuffer & buffer, T & d, uint8 header);


		template <typename T>
		inline static void load(typename enable_if<sizeof(T) == 1, T>::type & dst, const char* n) {
			LogTrace("void load(typename enable_if<sizeof(T) == 1, T>::type & dst, const char* n)");
			dst = static_cast<T>(*reinterpret_cast<const uint8*>(n));
			LogTraceReturnVoid;
		}

		template <typename T>
		inline static void load(typename enable_if<sizeof(T) == 2, T>::type & dst, const char* n) {
			LogTrace("void load(typename enable_if<sizeof(T) == 2, T>::type & dst, const char* n)");
			_msgpack_load16(T, n, &dst);
			LogTraceReturnVoid;
		}

		template <typename T>
		inline static void load(typename enable_if<sizeof(T) == 4, T>::type & dst, const char* n) {
			LogTrace("void load(typename enable_if<sizeof(T) == 4, T>::type & dst, const char* n)");
			_msgpack_load32(T, n, &dst);
			LogTraceReturnVoid;
		}

		template <typename T>
		inline static void load(typename enable_if<sizeof(T) == 8, T>::type & dst, const char* n) {
			LogTrace("void load(typename enable_if<sizeof(T) == 8, T>::type & dst, const char* n)");
			_msgpack_load64(T, n, &dst);
			LogTraceReturnVoid;
		}

	private:
		TBuffer * m_buffer;


	LIGHTINK_DISABLE_COPY(Unpacker)
	};


	template <typename TBuffer, typename T>
	RuntimeError unpack(TBuffer & buffer, T & v);

}


#include "Unpacker.cpp"
#include "UnpackerAdaptor.cpp"


#endif
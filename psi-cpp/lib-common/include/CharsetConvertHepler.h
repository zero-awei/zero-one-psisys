#pragma once
#ifndef _CHARSETCONVERTHEPLER_H_
#define _CHARSETCONVERTHEPLER_H_
#include <string>
/**
 * ×Ö·û´®±àÂë×ªÂë¹¤¾ßÀà
 */
class CharsetConvertHepler final
{
public:
	//************************************
	// Method:    unicodeToUtf8
	// FullName:  CharsetConvertHepler::unicodeToUtf8
	// Access:    public static 
	// Returns:   std::string ·µ»Ø×ª»»ºóµÄ×Ö·û´®
	// Qualifier: ½«Unicode×Ö·û´®×ª»»³ÉUTF8×Ö·û´®
	// Parameter: const std::wstring & wstr Unicode×Ö·û´®
	//************************************
	static std::string unicodeToUtf8(const std::wstring& wstr);

	//************************************
	// Method:    utf8ToUnicode
	// FullName:  CharsetConvertHepler::utf8ToUnicode
	// Access:    public static 
	// Returns:   std::wstring ·µ»Ø×ª»»ºóµÄ×Ö·û´®
	// Qualifier: ½«UTF8×Ö·û´®×ª»»³ÉUnicode×Ö·û´®
	// Parameter: const std::string & str UTF8×Ö·û´®
	//************************************
	static std::wstring utf8ToUnicode(const std::string& str);

	//************************************
	// Method:    unicodeToAnsi
	// FullName:  CharsetConvertHepler::unicodeToAnsi
	// Access:    public static 
	// Returns:   std::string ·µ»Ø×ª»»ºóµÄ×Ö·û´®
	// Qualifier: ½«Unicode×Ö·û´®×ª»»³ÉANSI×Ö·û´®
	// Parameter: const std::wstring & wstr Unicode×Ö·û´®
	//************************************
	static std::string unicodeToAnsi(const std::wstring& wstr);
	
	//************************************
	// Method:    ansiToUnicode
	// FullName:  CharsetConvertHepler::ansiToUnicode
	// Access:    public static 
	// Returns:   std::wstring ·µ»Ø×ª»»ºóµÄ×Ö·û´®
	// Qualifier: ½«ANSI×Ö·û´®×ª»»³ÉUnicode×Ö·û´®
	// Parameter: const std::string & str ANSI×Ö·û´®
	//************************************
	static std::wstring ansiToUnicode(const std::string& str);

	//************************************
	// Method:    utf8ToAnsi
	// FullName:  CharsetConvertHepler::utf8ToAnsi
	// Access:    public static 
	// Returns:   std::string ·µ»Ø×ª»»ºóµÄ×Ö·û´®
	// Qualifier: ½«UTF8×Ö·û´®×ª»»³ÉANSI×Ö·û´®
	// Parameter: const std::string & str UTF8×Ö·û´®
	//************************************
	static std::string utf8ToAnsi(const std::string& str);

	//************************************
	// Method:    ansiToUtf8
	// FullName:  CharsetConvertHepler::ansiToUtf8
	// Access:    public static 
	// Returns:   std::string
	// Qualifier: ½«ANSI×Ö·û´®×ª»»³ÉUTF8×Ö·û´®
	// Parameter: const std::string & str ANSI×Ö·û´®
	//************************************
	static std::string ansiToUtf8(const std::string& str);
};
#endif // _CHARSETCONVERTHEPLER_H_

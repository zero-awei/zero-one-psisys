
#include "stdafx.h"
#include "TestToken.h"
#include "JWTUtil.h"
#include <iostream>

// RSA ˽Կ
std::unique_ptr<std::string> RSA_PRIV_KEY = std::make_unique<std::string>(R"(
-----BEGIN PRIVATE KEY-----
MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDYJSiDqR0pQ6U6
104cVyy2zQoe3l6DxQ8XpiP+O17uODE5axgHnvWt0zNMMhijVQhphU4lx3eiKj1C
V5tRkPs7gYvygmaP2s0JWTrTF/He+FghLN0dvBCFRSDH5gOYOvlQlX8P+6EJ0UrO
JNQEyMOi1JBe8KxtYgwYYQVs9cp71VGaCq2N019a+MxruylDCLLSCPsZ45SIi22R
VmdrqoUVlFJEDGnc0n0Qttxbsp327kgXOu/Fc2Jg860iLD7OolNixJdQlMjthABf
L3Ooa1PtBQVSPFR/7tvUMQukZk+bAZ3knOP7N9M2xLcNE249Ak+Q9ulSjWoKxTnm
xeBw2t/PAgMBAAECggEADHXH6h8boT9XDRdQV23nE/qp9LGY/Tuk7RYUyRkfFdiD
be3wiq/tNcIRGPliVjgWrg6TPLZM/To2IdbvCzqyYPHM4YQG6ZARddKBA55DwTjL
y83MSWSIB0a+5wcpeeMccDrOAlvdIrW//DY/Sq9QJ9jdIbv6FKwsSlN9fpSEwbKl
TDqwZJCyc5KBKq7r6NixO/ksATi1uaQUfJT5b4sakGKUN5I7MwAjST4em7Ze8VVc
HGt1ClaTgLxKfPMurd0Ec+8o/3ex/PkU7Wx8AHqAj/IQsLdNB2arHePpcQVzHjsb
u4+zJSrtxOzrZlC/qfPObh8+o/i72K556ZfcEFjb8QKBgQDt2qD5sKn592+xtGXX
rzv/8G1CdE6Zy4WBUl33gov2rbGvmkrAeDGWV7dgTW0fPI9oXhV4Ioc7q61cDp8C
U9FDjDNpEEhUextq4VFjJWQ2tUvigyTkMFT7dEg1j35jbMGmvNh9jWQzdeM3Rheb
Q8VVGbZ5i2z4iGpfrDfStUeiiwKBgQDooow36Y5KZtvbnkF+C0nqQ7LC63ZsSBTS
UQgFWw5sBJssv9DsZIm1Ke14aHZftrDm67mg+/xsrw3+DZxwlaui8zA4PLpmTrGj
AnJ/2F9En8LZtb/ove+gXuQjZrNUsHh6+OpMWaEC1Flp3+jaPoaKZPp0ta/WYHPi
OEQ3uvh0TQKBgH0FvjeAtNe/R+aQfDey1EbjiYq0t9v/Ll2bfejrpcYz5oH3B/PD
Oc1crfbgu8r/eiHR0lcjTxH+W1FYHhyLEiP/Pcar2FkPnInBhZYnwVVAVnLpnCqV
fRXvOUVt93EraV7LRMA54cFq5dPX8/CY3tCsg03AC7dXfRJs46rNvqmhAoGACyR1
+Nub8B5bG3rKAkKCKNFTR5jFlEwjiytMag1BdJUH5a3OUPRD0ESQ1jqSqOT0NitG
Odq37XC5B9kZDB9vGB/zyE3IU8wjH/6nA06WyY+pYoodBgXK63CAFt39auoE60bu
2fdVCfCn07Vgzss94HUTtfFZ2bfG9SfixJSU/+UCgYEAyW1Si7qQRiNUSJWU8Jae
yFWOL1mvZRpXPUlg70H4wARoJjK6XgNKcE6GWbOedNtyiVJ7b07bmf9YJX2NWOzE
913vLOeLSlJeJAoQHEoYCM0nnOEcfUMiuOx59R4zk4RzSC64uK9PeguGSS6RaQwQ
8aj6l5u1SVtUNRb+ZjPCU8c=
-----END PRIVATE KEY-----)");

void TestToken::generateToken()
{
	PayloadDTO p;
	p.getAuthorities().push_back("SUPER_ADMIN");
	p.setUsername(u8"roumiou");
	p.setId("1");
	p.setExp(3600 * 30);
	std::cout << JWTUtil::generateTokenByRsa(p, RSA_PRIV_KEY->c_str()) << std::endl;
}

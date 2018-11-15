/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * Additions Copyright 2016 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file aws_iot_certifcates.c
 * @brief File to store the AWS certificates in the form of arrays
 */

#ifdef __cplusplus
extern "C" {
#endif

const char aws_root_ca_pem[] = {"-----BEGIN CERTIFICATE-----\n\
MIIE0zCCA7ugAwIBAgIQGNrRniZ96LtKIVjNzGs7SjANBgkqhkiG9w0BAQUFADCB\n\
yjELMAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQL\n\
ExZWZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJp\n\
U2lnbiwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxW\n\
ZXJpU2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0\n\
aG9yaXR5IC0gRzUwHhcNMDYxMTA4MDAwMDAwWhcNMzYwNzE2MjM1OTU5WjCByjEL\n\
MAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQLExZW\n\
ZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJpU2ln\n\
biwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxWZXJp\n\
U2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0aG9y\n\
aXR5IC0gRzUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCvJAgIKXo1\n\
nmAMqudLO07cfLw8RRy7K+D+KQL5VwijZIUVJ/XxrcgxiV0i6CqqpkKzj/i5Vbex\n\
t0uz/o9+B1fs70PbZmIVYc9gDaTY3vjgw2IIPVQT60nKWVSFJuUrjxuf6/WhkcIz\n\
SdhDY2pSS9KP6HBRTdGJaXvHcPaz3BJ023tdS1bTlr8Vd6Gw9KIl8q8ckmcY5fQG\n\
BO+QueQA5N06tRn/Arr0PO7gi+s3i+z016zy9vA9r911kTMZHRxAy3QkGSGT2RT+\n\
rCpSx4/VBEnkjWNHiDxpg8v+R70rfk/Fla4OndTRQ8Bnc+MUCH7lP59zuDMKz10/\n\
NIeWiu5T6CUVAgMBAAGjgbIwga8wDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8E\n\
BAMCAQYwbQYIKwYBBQUHAQwEYTBfoV2gWzBZMFcwVRYJaW1hZ2UvZ2lmMCEwHzAH\n\
BgUrDgMCGgQUj+XTGoasjY5rw8+AatRIGCx7GS4wJRYjaHR0cDovL2xvZ28udmVy\n\
aXNpZ24uY29tL3ZzbG9nby5naWYwHQYDVR0OBBYEFH/TZafC3ey78DAJ80M5+gKv\n\
MzEzMA0GCSqGSIb3DQEBBQUAA4IBAQCTJEowX2LP2BqYLz3q3JktvXf2pXkiOOzE\n\
p6B4Eq1iDkVwZMXnl2YtmAl+X6/WzChl8gGqCBpH3vn5fJJaCGkgDdk+bW48DW7Y\n\
5gaRQBi5+MHt39tBquCWIMnNZBU4gcmU7qKEKQsTb47bDN0lAtukixlE0kF6BWlK\n\
WE9gyn6CagsCqiUXObXbf+eEZSqVir2G3l6BFoMtEMze/aiCKm0oHw0LxOXnGiYZ\n\
4fQRbxC1lfznQgUy286dUV4otp6F01vvpX1FQHKOtw5rDgb7MzVIcbidJ4vEZV8N\n\
hnacRHr2lVz2XTIIM6RUthg/aFzyQkqFOFSDX9HoLPKsEdao7WNq\n\
-----END CERTIFICATE-----\n"};

const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDWTCCAkGgAwIBAgIUZ0woixgE+G0+E8JKWN3Mdh3kzZ4wDQYJKoZIhvcNAQEL\n\
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n\
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTE4MTEwODIxMDcx\n\
NVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n\
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAK10LskpQk9IKfdg53Wm\n\
K5KT9Erp5zNTRKB0HSVQ9geizHYuluNGV0YX+Rt4Bm5+Fw0ywA5A40ahqnM9BILu\n\
JzWsZgxhbtmbqytdsM73aU63SU+YV58jgwFQ7hkxkCFjoFI+uIKR9FT1MDUoQn+W\n\
3kSRCmeaURHEVrAKBdIFYtOAawIyYhh+L43rtxyUFsF0KKhR3cCRi0q7yYBZfaIp\n\
9sApiEbsCkGG1fUalI1/u0KJKV/d8ctQwG33jhXSihFS7mORcAhfUWUyR7ii7e1P\n\
uEX4sEPScA9TKPLN1dxvvfLbJqA+/dVUq+e+5xfetSnV7KsGnzsJBiraCMEQvMUr\n\
GTcCAwEAAaNgMF4wHwYDVR0jBBgwFoAU31ouH2f/LUR/YD+80eHS7QUkSZ4wHQYD\n\
VR0OBBYEFHELLRskziU/1iWRmUubz4IO9tZ+MAwGA1UdEwEB/wQCMAAwDgYDVR0P\n\
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBmi9zFGQ5Q99qCSZfGI9459CTh\n\
oom9jSNCLvBgTxqVRKo4RbBxsTjVZDZLt7v5ogLke+J24ricOixPemwz7+nDE7Zt\n\
dk8bTWUCWHbQLunQ2SaR2Ie2d2XPvD9ysExpmF5t+U6byTR7lHOtGrkaWxi5tABt\n\
Z51lUb6ufBVfCiHEtI3kbOkObR+o/qi2C11LeME7HP4yXzowuroUdX+FS4CNVlMg\n\
q01b2s01DhX4eOInKVTxjxjlRMo7YRE7iXIXLl51ILUHKFlbPu6UZbyEkkeQZghF\n\
Qx9fZ+FSIiDl53tF7ODNDAoye0D6OivIBfPvbFoYE+Xc9/8lOWZSjdamu6Pv\n\
-----END CERTIFICATE-----\n"};

const char private_pem_key[] = {"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEowIBAAKCAQEArXQuySlCT0gp92DndaYrkpP0SunnM1NEoHQdJVD2B6LMdi6W\n\
40ZXRhf5G3gGbn4XDTLADkDjRqGqcz0Egu4nNaxmDGFu2ZurK12wzvdpTrdJT5hX\n\
nyODAVDuGTGQIWOgUj64gpH0VPUwNShCf5beRJEKZ5pREcRWsAoF0gVi04BrAjJi\n\
GH4vjeu3HJQWwXQoqFHdwJGLSrvJgFl9oin2wCmIRuwKQYbV9RqUjX+7QokpX93x\n\
y1DAbfeOFdKKEVLuY5FwCF9RZTJHuKLt7U+4RfiwQ9JwD1Mo8s3V3G+98tsmoD79\n\
1VSr577nF961KdXsqwafOwkGKtoIwRC8xSsZNwIDAQABAoIBAGg/xQLYTmdSKw7o\n\
ahS2y8dsL057KJ8bc8qwHvhXoZdTTGnXdI6irz+Mlwbga5UrKXWgQ/gNHcxMzCI4\n\
0SZUNrK2rBrS0InvWsBUrjimUN+jn2c8W6Vk9Y7r8j6oIEVBGJF16vVm/Z+2QcQh\n\
L1558ZrqRYOhJwpzo9poG7lvzUbqEVLxNmud2GhHF6BXf9BhJmnGR5cyapvY9Esz\n\
leGhyjj5xKWIg1ZtLo/OtlUz7+ZyDX+bdGMYhOkrP9VHuPC/lje6fwUvZc98X7jg\n\
Euyh5ciqZlFJGdNgWAhaMVurTU3JwZ+lA5UQ3m5II6EepaxhU7iFfFWW4ThcbKeB\n\
ABGdk2kCgYEA3MoZtlI22EMIfEusnwPfX4EXOVP0Id9rUZyZAOLVZ6JkGXf2w8eW\n\
jJ4rry2kFW2vDRt5y8bckUO1+mjhvZW4kA1Ly/CHN+qVSa4HtpAhG8N5k6MLMuKT\n\
SeJ4+5m9gBgtIG8epHrIqQSs/M+SWMZ2awt6LVbTMErfYQ57zgJL2NsCgYEAyR2R\n\
wApWXf4Tb31mkQsDiObhuSq3+2rPavLWZv4uMdwVRbzPo4oz81Wwpsl2hl2wJRu+\n\
upz/vJW4fNPALR4U3E94Gl55vjkvD+6sesoVybVkI9MlG3dpfkj4n4wF9yk3djKk\n\
nu83BgTHLI9zWEsf0BILhrOezMzkn1cJAzQ1cdUCgYAyJYDjhRbJ1afGu1VQpIuG\n\
YIaK0cOgMeNpHN0vc1Wu/RYpJrMYUmuiMoaPehlLeKcKnhPysY8FO1DIuCuVaL0L\n\
ksmFX3MGwzP3ERzVXTT33lTtsFlpzEZRwKtj0c5VmqgdNr/J8c1DfjlgDjEaErFw\n\
rKGqTI8Y59iGbci2yJS7gwKBgHjgmt+P1wU7Vrcl6eW3dvJrwrOmZ1pngi9HsXHJ\n\
yD4Th32Y1Dv5LuxMTpaQc/qiiOJk4KgNAPB6FJ6CLvlvIR6hbRB8RDP+7rhmvag3\n\
mgzYR0349E6j4PYUKcrLQDKjxT/3hFY6dRna+VNhDPS+gmpuzhqyDvoNFERo7XPN\n\
h2nZAoGBAJyqk8ZhLGKx2R01h3VBUEkvIBnqiXdxjNzgFOMj/lRBzrv0WIh+j552\n\
SYsLtdzRRd+GiMyOsYWYmDC8Q2g5a4McSpHh1xrDF4nFaTQiq6FoFotRstLbN3AP\n\
rkmc/juVQORqzPK2DfN/70MKkRmHiDGCnvXrIFLO6+RmZGNWbvFO\n\
-----END RSA PRIVATE KEY-----\n"};


#ifdef __cplusplus
}
#endif


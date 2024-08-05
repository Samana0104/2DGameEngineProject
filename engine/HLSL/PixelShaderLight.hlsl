// �ȼ����̴� , float1(x), float2(x,y), float3(x,y,z), float4(x,y,z,w)
// ��ȯ�� = FLOAT4(R,G,B,A)�� ��ȯ�Ǿ�� �Ѵ�.
// �ø�ƽ(�ṉ̀���) : SV_POSITION, SV_TARGET
// ���̴� �Է� �� ��� �����ʹ� 
// ������ �������Ϳ� ���� �� ��� �Ǿ�� �Ѵ�.

Texture2D g_txTexture : register(t0);
SamplerState sampler0 : register(s0);

struct PS_In
{
	float4 p : SV_POSITION;// �ݵ�� float4
	float4 c  :COLOR;
	float2 t  :TEXCOORD0;
    float2 v : VPOS;
};

struct PS_Out
{
	float4 c : SV_Target;
};

PS_Out PSMain( PS_In psIn )
{
	PS_Out  psOut=(PS_Out)0;
	float4 pixel = g_txTexture.Sample(sampler0, psIn.t);

    psOut.c = pixel * psIn.c;

    if (psOut.c.r <= 0.1f)
    {
        psOut.c.rgb *= 4.f;
    }
    else if (psOut.c.r <= 0.3f)  // threshhold
    {
        psOut.c.r *= 2.5f;
    }
    else
    {
        psOut.c.rgb *= 1.5f;
    }
	
    if (psOut.c.g <= 0.3f)  // threshhold
        psOut.c.g *= 2.5f;

    if (psOut.c.b <= 0.3f)  // threshhold
        psOut.c.b *= 2.5f;
    return psOut;
}
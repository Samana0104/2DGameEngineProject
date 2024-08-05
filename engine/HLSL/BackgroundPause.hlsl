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
    psOut.c = psIn.c;
	
    float alphaStep = smoothstep(0.6f, 0.4f, abs(psIn.v.y));
    psOut.c.a = 0.7f + 0.2*alphaStep;
    return psOut;
}
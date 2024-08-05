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
 //   const vec2 windowSize = MyWindow::GetInstance().GetWindowSizeVec2();
	//return { mCartesianSize.x * _pos.x / windowSize.x - mCartesianSize.x / 2,
	//		-mCartesianSize.y * _pos.y / windowSize.y + mCartesianSize.y / 2 };

    float r = sqrt(pow(psIn.v.x, 2) + pow(psIn.v.y, 2));
	
//	float theta = 
    float smooth = smoothstep(0.3f, 1.0f, 1 - r);
    psOut.c = psIn.c * smooth;

    if (r < 0.2f)
        psOut.c *= 0.98f;
    return psOut;
}
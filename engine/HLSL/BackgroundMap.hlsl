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
    float4 blue = float4(38.f / 255.f, 43.f / 255.f, 109.f / 255.f, 1.f);
    float4 blue2 = float4(50.f / 255.f, 55.f / 255.f, 141.f / 255.f, 1.f);
    float4 inversePixel;
    float r = pow(psIn.v.x, 2) + pow(psIn.v.y, 2);
//	float theta = 

    psOut.c = saturate(pixel * blue);
    inversePixel = float4(1 - pixel.r, 1 - pixel.g, 1 - pixel.b, pixel.a);
    psOut.c += saturate(inversePixel * blue2);
    
    //psOut.c *= 1 - length(psIn.v.x)
    psOut.c *= smoothstep(0.1f, 1.f,-0.7f * r + 1.25f);
    return psOut;
}
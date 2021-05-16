#pragma once

namespace Vtil
{
	using namespace System;

	public ref class Utillity
	{
	public:
		static String^ Utillity::Decrypt(String^ cipher);
		static String^ ReadLiscense(String^ assembly);
		static cli::array<Byte>^ Utillity::TTS(String^ voice, String^ aikana);
		static void Play(cli::array<Byte>^ data);
		static cli::array<Byte>^ PcmToWave(cli::array<Byte>^ pcm);
	};
}
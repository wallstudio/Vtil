#pragma once

namespace Vtil
{
	using namespace System;

	public ref class Utillity
	{
	public:
		static String^ Utillity::Decrypt(String^ cipher);
		static String^ ReadLiscense(String^ assembly);
	};
}
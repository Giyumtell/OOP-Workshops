#ifndef CONFIRMATION_SENDER_H_
#define CONFIRMATION_SENDER_H_
#include "Reservation.h"
namespace sdds
{
	class ConfirmationSender
	{
	public:
		ConfirmationSender()
		{
		}
		~ConfirmationSender();
		ConfirmationSender(ConfirmationSender& other);
		ConfirmationSender(ConfirmationSender&& other)noexcept;
		ConfirmationSender& operator=(ConfirmationSender& other);
		ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& ostr, ConfirmationSender& other);
	private:
		const Reservation** m_res = nullptr;
		size_t max = 0;
	};
}
#endif // !CONFIRMATION_SENDER_H_

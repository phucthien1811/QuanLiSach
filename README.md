##Hạn deadline 
Phúc Thiên (24/11) -- done -- Tú Tài (26/11) -- done -- Duy (28/11) -- done -- Phúc (30/11) -- Hoàng (1/12) 
Người làm sau pull code người làm trước về để sử dụng

##PHUCTHIEN
T2 - Core & Template 

File thao tác:

Include/CBook.h & Source/CBook.cpp

Include/CReader.h & Source/CReader.cpp

Include/CLoanTicket.h & Source/CLoanTicket.cpp

Include/CGenericList.h (Chứa Template Class)

Lưu ý:

Template: Viết TOÀN BỘ code trong file .h. KHÔNG tạo file .cpp cho CGenericList.

Naming: Biến member phải có m_ (ví dụ: m_strName, m_iID).

Destructor: Class nào có con trỏ thì Destructor phải delete.

##TRUONGTUTAI

File thao tác:

Include/CFileHandler.h & Source/CFileHandler.cpp

Lưu ý:

Standard II.18: Có open thì bắt buộc phải có close.

Path: Dùng đường dẫn tương đối Data/Sach.txt. Cấm tuyệt đối dùng đường dẫn cứng kiểu C:\Users\Admin....

Format Data:

Sách: ISBN|Ten|TacGia|NXB|Nam|TrangThai

Bạn đọc: Ma|Ten|NgayTG

#DUY: Quản lí sách

File thao tác:

Include/CBookManager.h & Source/CBookManager.cpp

Lưu ý:

Logic Xóa: Trước khi xóa phải check TrangThai == 0.

Standard II.19: Không dùng magic number (số 0, 1 vô nghĩa). Hãy #define AVAILABLE 0.

Phối hợp với T3 để lưu file ngay sau khi Thêm/Xóa thành công.

#PHUC: Mượn trả

File thao tác:

Include/CLoanManager.h & Source/CLoanManager.cpp

Lưu ý:

Pointer Check: Khi gọi hàm FindBook từ T4, phải kiểm tra if (pBook != NULL) rồi mới được thao tác tiếp.

Logic Mượn:

Check sách tồn tại?

Check sách có rảnh không?

Tạo phiếu mượn -> Add vào List.

Update trạng thái sách thành BẬN.

👤 HOÀNG: T1 - UI & System (Làm xuyên suốt)

File thao tác:

Include/CAppSystem.h & Source/CAppSystem.cpp

Include/CUIManager.h & Source/CUIManager.cpp

Main.cpp

Lưu ý:

Standard II.13

Không xử lý logic nghiệp vụ (cộng trừ nhân chia) ở tầng giao diện. Chỉ gọi hàm từ Manager. 

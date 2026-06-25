#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>
#include <memory>

// طبقة الاستدلال النفسي والسلوكي المتقدمة
class AdvancedPsychologyAnalyzer {
public:
    // مصفوفة الحالات: [0] عصبي/منزعج، [1] خائف/قلق، [2] طموح/متحمس، [3] مستقر/طبيعي
    std::vector<double> infer_emotional_state(const std::string& text) {
        std::vector<double> states = {0.1, 0.1, 0.1, 0.7}; // افتراض الحالة المستقرة أولاً

        // 1. فحص مؤشرات الغضب والانزعاج (جمل حادة، صياح رقمي)
        if (text.find("عصبي") != std::string::npos || text.find("منزعج") != std::string::npos || text.find("!!") != std::string::npos) {
            states[0] += 0.65; // رفع مؤشر الغضب
            states[3] -= 0.40; // خفض الاستقرار
        }
        // 2. فحص مؤشرات الخوف والقلق (البحث عن حماية أو أمان)
        if (text.find("خائف") != std::string::npos || text.find("أمان") != std::string::npos || text.find("حماية") != std::string::npos) {
            states[1] += 0.70; // رفع مؤشر الخوف
            states[3] -= 0.30;
        }
        // 3. فحص مؤشرات الطموح والحماس الشديد (شغف الابتكار والسرعة)
        if (text.find("اخترع") != std::string::npos || text.find("سريع") != std::string::npos || text.find("أقوى") != std::string::npos) {
            states[2] += 0.75; // رفع مؤشر الطموح
            states[3] -= 0.20;
        }

        // دالة التسوية غير الخطية (Hyperbolic Tangent) لحصر المنطق بـ كفاءة السيليكون
        for (double& score : states) {
            score = std::tanh(score);
            if (score < 0) score = 0; // منع القيم السالبة بالرام
        }
        return states;
    }
};

int main() {
    std::cout << "[👑] إطلاق المحرك العالمي المطور لفك الشفرة السلوكية البشرية..." << std::endl;
    std::cout << "============================================================" << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();

    // جرب تغير هذا النص بيدك داخل نانو وشوف شلون الكود يكتشف نفسيتك!
    std::string user_payload = "أنا منزعج جداً من بطء السيرفرات وأريد حل سريع فوراً!!";

    std::unique_ptr<AdvancedPsychologyAnalyzer> core_analyzer = std::make_unique<AdvancedPsychologyAnalyzer>();
    std::vector<double> result_matrix = core_analyzer->infer_emotional_state(user_payload);

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> total_time = end_time - start_time;

    std::cout << "[*] النص المدخل: \"" << user_payload << "\"" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "[😡] نسبة العصبية والانزعاج: " << result_matrix[0] * 100.0 << "%" << std::endl;
    std::cout << "[😨] نسبة الخوف والقلق النفسي: " << result_matrix[1] * 100.0 << "%" << std::endl;
    std::cout << "[🔥] نسبة الطموح والحماس العالي: " << result_matrix[2] * 100.0 << "%" << std::endl;
    std::cout << "[🧘] نسبة الاستقرار الروحي والطبيعي: " << result_matrix[3] * 100.0 << "%" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    // اتخاذ القرار الذكي لـ تخصيص النظام
    double max_score = result_matrix[0];
    int dominant_state = 0;
    for(int i = 1; i < 4; i++) {
        if(result_matrix[i] > max_score) {
            max_score = result_matrix[i];
            dominant_state = i;
        }
    }

    if (dominant_state == 0) std::cout << "[🚨] قرار النظام: المستخدم غاضب! تقليل وقت الانتظار وتوفير حل فوري لمعالجة انزعاجه." << std::endl;
    else if (dominant_state == 1) std::cout << "[🔒] قرار النظام: المستخدم قلق! تفعيل بروتوكولات الأمان العالية لطمأنته." << std::endl;
    else if (dominant_state == 2) std::cout << "[🚀] قرار النظام: المستخدم طموح! فتح قنوات المعالجة الفائقة والأكواد المتقدمة." << std::endl;
    else std::cout << "[✨] قرار النظام: الحالة مستقرة. استمرار العمل بالوضع الطبيعي." << std::endl;

    std::cout << "[⚡] السرعة الفائقة لفك السلوك: " << total_time.count() << " ملي ثانية!" << std::endl;

    return 0;
}


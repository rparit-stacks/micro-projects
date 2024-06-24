float percentag(vector<int> &subject_number)
{
    // Calculate percentage
    float sum = 0.0;
    for (int i = 0; i < user_input; i++)
    {
        sum += subject_number[i];
    }

    return (sum / (user_input * 100)) * 100;
}

void CGPA(vector<int> &subject_number)
{
    // Calculate percentage
    float sum = 0.0;
    for (int i = 0; i < user_input; i++)
    {
        sum += subject_number[i];
    }

    cout << endl;
    cout << "Congratulations! Your CGPA is: " << percentag(subject_number) / 9.5 << "%" << endl;
}
#ifndef TEST_LIST_MODEL_HPP
#define TEST_LIST_MODEL_HPP

#include "core_data_model/i_list_model.hpp"
#include "core_data_model/abstract_item_model.hpp"

#include <memory>

namespace wgt
{
class OldTestListModel: public IListModel
{
public:
	OldTestListModel( bool shortList = false );
	OldTestListModel( const OldTestListModel& rhs );
	virtual ~OldTestListModel();

	OldTestListModel& operator=( const OldTestListModel& rhs );

	virtual IItem * item( size_t index ) const override;
	virtual size_t index( const IItem * item ) const override;

	virtual bool empty() const override;
	virtual size_t size() const override;
	virtual int columnCount() const override;
	virtual Variant getData( int column, size_t roleId ) const override;
	virtual bool setData( int column, size_t roleId, const Variant & data ) override;

private:
	struct Implementation;
	std::unique_ptr<Implementation> impl_;
};


class TestListModel: public AbstractListModel
{
public:
	TestListModel( bool shortList = false );
	TestListModel( const TestListModel& rhs );
	virtual ~TestListModel();

	TestListModel& operator=( const TestListModel& rhs );

	virtual Variant getData( int row, int column, size_t roleId ) const override;
	virtual bool setData( int row, int column, size_t roleId, const Variant & data ) override;

	virtual AbstractItem * item( int row ) const override;
	virtual int index( const AbstractItem * item ) const override;

	virtual int rowCount() const override;
	virtual int columnCount() const override;

	virtual Connection connectPreItemDataChanged( DataCallback callback ) override;
	virtual Connection connectPostItemDataChanged( DataCallback callback ) override;

private:
	struct Implementation;
	std::unique_ptr<Implementation> impl_;
};
} // end namespace wgt
#endif
